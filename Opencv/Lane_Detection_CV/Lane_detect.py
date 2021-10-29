#!/usr/bin/env python3
import copy
import numpy as np
import cv2
class TrackVision():

    def __init__(self):

        self.pyrDown = 1
        self.mask_ratio_array = [1.0,0.4]
        
        
        #Rectangualr area to remove from image calculation to 
        # eliminate the vehicle. Used as ratio of overall image width and height
        # "width ratio,height ratio"
        self.maskRectRatioWidthHeight = np.array([float(self.mask_ratio_array[0]),float(self.mask_ratio_array[1])])
        
        #Pixy image size parameters
        self.pixyImageWidth = 72*3
        self.pixyImageHeight = 52*3
        
        #Only used for debugging line finding issues
        self.lineFindPrintDebug = False
        self.lineMethodsUsedCount = [0, 0, 0, 0, 0, 0, 0]
        self.lineMethodUsed = 0

        (self.pX0, self.pY0, self.pX1, self.pY1) = (0,1,2,3)
        
        #Testing
        self.useBogusData=False
        self.publishSecondVector=True
        self.sortRightToLeft=False
        self.switchVectorPoints=True
        self.stage=0
        self.startTime=0
        self.testAllConfigs=False

        self.bogusOffsetNumber = 3
          
        if self.sortRightToLeft:
            self.bogusDataTest=[[int((self.pixyImageWidth*0.8)+
                self.bogusOffsetNumber),0,
                int(self.pixyImageWidth*0.8),self.pixyImageHeight],
                [int((self.pixyImageWidth*0.2)-self.bogusOffsetNumber),0,
                int(self.pixyImageWidth*0.2),self.pixyImageHeight]]
        else:
            self.bogusDataTest=[[int((self.pixyImageWidth*0.2)+
                self.bogusOffsetNumber),0,
                int(self.pixyImageWidth*0.2),self.pixyImageHeight],
                [int((self.pixyImageWidth*0.8)-self.bogusOffsetNumber),0,
                int(self.pixyImageWidth*0.8),self.pixyImageHeight]]

        if self.switchVectorPoints:
            (self.pX0, self.pY0, self.pX1, self.pY1) = (2,3,0,1)

    def findLines(self, passedImage):
        
        
        #Testing
        if self.testAllConfigs:
            if self.stage == 0:
                self.sortRightToLeft=False
                self.switchVectorPoints=False
                self.startTime = self.timeStamp
                self.stage = 1
            elif (((self.timeStamp - self.startTime) > 30*1e6) and (self.stage == 1)):
                self.sortRightToLeft=False
                self.switchVectorPoints=True
                self.stage = 2
            elif (((self.timeStamp - self.startTime) > 40*1e6) and (self.stage == 2)):
                self.sortRightToLeft=True
                self.switchVectorPoints=False
                self.stage = 3
            elif (((self.timeStamp - self.startTime) > 50*1e6) and (self.stage == 3)):
                self.sortRightToLeft=True
                self.switchVectorPoints=True
                self.stage = 4
                

        
        #convert image to grayscale
        passedImageGray = cv2.cvtColor(passedImage,cv2.COLOR_BGR2GRAY)
        cv2.imshow("gray",passedImageGray)
        #Image dimensions
        imageHeight, imageWidth = passedImageGray.shape[:2]
        
        #Threshold image black and white
        passedImageGrayThresh = cv2.bitwise_not(cv2.threshold(
            passedImageGray, 50, 255, cv2.THRESH_BINARY)[1])
        
        #Create image mask background
        maskWhite = np.ones(passedImageGrayThresh.shape[:2], dtype="uint8") * 255
        cv2.imshow("mask_white",maskWhite)
        #calculate points to be masked based on provided ratio
        maskVehicleBoxTopLeftXY = (int(imageWidth*(1.0-self.maskRectRatioWidthHeight[0])/2.0), 
            int(imageHeight*(1.0-self.maskRectRatioWidthHeight[1])))
        
        #calculate points to be masked based on provided ratio
        maskVehicleBoxBottomRightXY = (int(imageWidth*(1.0+self.maskRectRatioWidthHeight[0])/2.0), 
            int(imageHeight))
        
        maskVehicle = cv2.rectangle(maskWhite,maskVehicleBoxTopLeftXY,
            maskVehicleBoxBottomRightXY,color=0,thickness=-1)
        cv2.imshow("mask_vehicle",maskVehicle)
        
        #Mask out the area of the vehicle
        passedImageGrayThreshMasked = cv2.bitwise_and(passedImageGrayThresh, 
            passedImageGrayThresh, mask=maskVehicle)
        cv2.imshow("bitwise filter",passedImageGrayThreshMasked)
        
        #Find contours
        cnts, hierarchy = cv2.findContours(passedImageGrayThreshMasked.copy(),
            cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
        
        returnedImageDebug=passedImage

        #Max number of found contours to process based on area of return, largest returned first
        maxCnt = 2
        if len (cnts) < maxCnt:
            maxCnt = len(cnts)
        cnt = sorted(cnts, key=cv2.contourArea, reverse=True)[0:maxCnt]

        #Take largest contours and sort left to right
        if len (cnts) > 1:
            boundingBoxes = [cv2.boundingRect(c) for c in cnt]
            (cnt, boundingBoxes) = zip(*sorted(zip(cnt, boundingBoxes),
                key=lambda b:b[1][0], reverse=self.sortRightToLeft))

        #Initialize and/or clear existing found line vector array
        pixyScaledVectorArray = np.empty([0,4], int)

        #Used to determine what line is mapped in message from debug image
        lineNumber=0

        #Loop through contours
        for cn in cnt:
                #Paint all the areas found in the contour
            cv2.fillPoly(returnedImageDebug,pts=[cn],color=(0,0,255))
            
            #Find lines from contours using least square method
            [vectorX,vectorY,linePointX,linePointY] = cv2.fitLine(cn,cv2.DIST_L2,0,0.01,0.01)
            
            if (linePointX >= 1.0) and (linePointY >= 1.0):
                #Easy avoid divide by zero
                if vectorY == 0:
                    vectorY = 1e-4
                if vectorX == 0:
                    vectorX = 1e-4

                #Calculate line points to see if they exceeds any bounds of the image, correct if they do
                topLeftX = int((-linePointY*vectorX/vectorY)+linePointX)
                bottomRightX = int(((imageHeight-linePointY)*vectorX/vectorY)+linePointX)
                topLeftY = 0
                bottomRightY = imageHeight
                self.lineMethodUsed = 0
                
                if (topLeftX <= 0) and (bottomRightX > imageWidth):
                    self.lineMethodUsed = 1
                    topLeftY = int(((-linePointX)*vectorY/vectorX)+linePointY)
                    bottomRightY = int(((imageWidth-linePointX)*vectorY/vectorX)+linePointY)
                    topLeftX = 0
                    bottomRightX = imageWidth

                elif (topLeftX > imageWidth) and (bottomRightX < 0):
                    self.lineMethodUsed = 2
                    topLeftY = int(((imageWidth-linePointX)*vectorY/vectorX)+linePointY)
                    bottomRightY = int(((-linePointX)*vectorY/vectorX)+linePointY)
                    topLeftX = imageWidth
                    bottomRightX = 0

                elif (topLeftX <= 0) and (bottomRightX < imageWidth):
                    self.lineMethodUsed = 3
                    topLeftY = int(((-linePointX)*vectorY/vectorX)+linePointY)
                    bottomRightY = imageHeight
                    topLeftX = 0
                    bottomRightX = int(((imageHeight-linePointY)*vectorX/vectorY)+linePointX)

                elif (topLeftX > 0) and (bottomRightX > imageWidth):
                    self.lineMethodUsed = 4
                    topLeftY = 0
                    bottomRightY = int(((imageWidth-linePointX)*vectorY/vectorX)+linePointY)
                    topLeftX = int((-linePointY*vectorX/vectorY)+linePointX)
                    bottomRightX = imageWidth

                elif (topLeftX > imageWidth) and (bottomRightX > 0):
                    self.lineMethodUsed = 5
                    topLeftY = imageHeight
                    bottomRightY = int(((imageWidth-linePointX)*vectorY/vectorX)+linePointY)
                    topLeftX = int(((imageHeight-linePointY)*vectorX/vectorY)+linePointX)
                    bottomRightX = imageWidth

                elif (topLeftX < imageWidth) and (bottomRightX < 0):
                    self.lineMethodUsed = 6
                    topLeftY = int((-linePointX*vectorY/vectorX)+linePointY)
                    bottomRightY = 0
                    topLeftX = 0
                    bottomRightX = int((linePointY)*(-vectorX/vectorY)+linePointX)
                
                
                #Extra safety
                if topLeftX < 0:
                    topLeftX=0
                elif topLeftX > imageWidth:
                    topLeftX=imageWidth
                if bottomRightX < 0:
                    bottomRightX=0
                elif bottomRightX > imageWidth:
                    bottomRightX=imageWidth
                if topLeftY < 0:
                    topLeftY=0
                elif topLeftY > imageHeight:
                    topLeftY=imageHeight
                if bottomRightY < 0:
                    bottomRightY=0
                elif bottomRightY > imageHeight:
                    bottomRightY=imageHeight

                #Add line method used to array count
                self.lineMethodsUsedCount[self.lineMethodUsed]+=1
                
                #Scale into Pixy camera units
                topLeftXScaled = int(topLeftX*(self.pixyImageWidth/imageWidth))
                bottomRightXScaled = int(bottomRightX*(self.pixyImageWidth/imageWidth))
                topLeftYScaled = int(topLeftY*(self.pixyImageWidth/imageWidth))
                bottomRightYScaled = int(bottomRightY*(self.pixyImageWidth/imageWidth))

                if self.lineFindPrintDebug:
                    self.get_logger().info('\n\nlineMethodUsed:{:d},lineMethodsUsedCount:{:s}'.format(
                        self.lineMethodUsed,str(self.lineMethodsUsedCount)))
                    self.get_logger().info('vectorX:{:f},vectorY:{:f},linePointX:{:f},linePointY:{:f}'.format(
                        float(vectorX),float(vectorY),float(linePointX),float(linePointY)))
                    self.get_logger().info('topLeftX:{:d},topLeftY:{:d},bottomRightX:{:d},bottomRightY:{:d}'.format(
                        topLeftX,topLeftY,bottomRightX,bottomRightY))
                    returnedImageDebug = cv2.line(returnedImageDebug,(topLeftX,topLeftY),
                        (bottomRightX,bottomRightY),(255,128,128),2)

                #Append found line points to pixy found line vector array
                pixyScaledVectorArray = np.append(pixyScaledVectorArray,
                    np.array([[topLeftXScaled,topLeftYScaled,bottomRightXScaled,bottomRightYScaled]]),axis=0)
                #Increment line number
                lineNumber += 1
        
        #Testing
        if self.useBogusData:
            if self.sortRightToLeft:
                self.bogusDataTest=[[int((self.pixyImageWidth*0.8)+
                    self.bogusOffsetNumber),0,
                    int(self.pixyImageWidth*0.8),self.pixyImageHeight],
                    [int((self.pixyImageWidth*0.2)-self.bogusOffsetNumber),0,
                    int(self.pixyImageWidth*0.2),self.pixyImageHeight]]
            else:
                self.bogusDataTest=[[int((self.pixyImageWidth*0.2)+
                    self.bogusOffsetNumber),0,
                    int(self.pixyImageWidth*0.2),self.pixyImageHeight],
                    [int((self.pixyImageWidth*0.8)-self.bogusOffsetNumber),0,
                    int(self.pixyImageWidth*0.8),self.pixyImageHeight]]

            if self.switchVectorPoints:
                (self.pX0, self.pY0, self.pX1, self.pY1) = (2,3,0,1)
            else:
                (self.pX0, self.pY0, self.pX1, self.pY1) = (0,1,2,3)

            pixyScaledVectorArray = np.array(self.bogusDataTest)

        
        #Border for vehicle mask
        returnedImageDebug = cv2.rectangle(returnedImageDebug,maskVehicleBoxTopLeftXY,
            maskVehicleBoxBottomRightXY, color=(128,128,0),thickness=3)

        #Calcualte background for pixy image space
        debugPixyMessageTopLeftXY = (int((imageWidth/2)-(self.pixyImageWidth/2)),
            int((imageHeight/2)-(self.pixyImageHeight/2)))

        #Create background for pixy image space
        returnedImageDebug = cv2.rectangle(returnedImageDebug,debugPixyMessageTopLeftXY,
            ((debugPixyMessageTopLeftXY[0]+self.pixyImageWidth),
            (debugPixyMessageTopLeftXY[1]+self.pixyImageHeight)),(0,255,0),-1)
        
        for lineNumber in range(len(pixyScaledVectorArray)):
            #Draw the found line in image space
            returnedImageDebug = cv2.line(returnedImageDebug,
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][0],
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][1]),
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][2],
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][3]),
                (255,128,128),1)
            
            #Draw box point for top left XY for Pixy space debug image
            returnedImageDebug = cv2.rectangle(returnedImageDebug,
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][0]-1, 
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][1]-1),
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][0]+1, 
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][1]+1),
                (0,0,255),-1)
            
            #Draw box point for bottom right XY for Pixy space debug image
            returnedImageDebug = cv2.rectangle(returnedImageDebug,
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][2]-1,
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][3]-1),
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][2]+1, 
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][3]+1),
                (0,0,255),-1)
            
            #Write text for top left XY for Pixy space debug image
            returnedImageDebug = cv2.putText(
                returnedImageDebug, '{:d},{:d}'.format(
                pixyScaledVectorArray[lineNumber][0],pixyScaledVectorArray[lineNumber][1]), 
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][0]-20+(20*lineNumber), 
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][1]), 
                cv2.FONT_HERSHEY_SIMPLEX, 0.25, (255,0,0), 1, cv2.LINE_AA)
            
            #Write text for bottom right XY for Pixy space debug image
            returnedImageDebug = cv2.putText(returnedImageDebug, '{:d},{:d}'.format(
                pixyScaledVectorArray[lineNumber][2],pixyScaledVectorArray[lineNumber][3]),
                (debugPixyMessageTopLeftXY[0]+pixyScaledVectorArray[lineNumber][2]-20+(20*lineNumber), 
                debugPixyMessageTopLeftXY[1]+pixyScaledVectorArray[lineNumber][3]), 
                cv2.FONT_HERSHEY_SIMPLEX, 0.25, (255,0,0), 1, cv2.LINE_AA)

            #Write the line number for message
            returnedImageDebug = cv2.putText(returnedImageDebug, 'm{:d}'.format(
                lineNumber),
                (int((pixyScaledVectorArray[lineNumber][0]+
                pixyScaledVectorArray[lineNumber][2])/2.0+
                debugPixyMessageTopLeftXY[0]-20+(20*lineNumber)),
                int((pixyScaledVectorArray[lineNumber][1]+
                pixyScaledVectorArray[lineNumber][3])/2.0+
                debugPixyMessageTopLeftXY[1])), 
                cv2.FONT_HERSHEY_SIMPLEX, 0.35, (0,0,255), 1, cv2.LINE_AA)
       
        return(returnedImageDebug), (pixyScaledVectorArray)
    
    def pixyImageCallback(self, scene):
        scenePyr = copy.deepcopy(scene)
        if self.pyrDown > 0:
            for i in range(self.pyrDown):
                scenePyr = cv2.pyrDown(scenePyr)
        sceneDetect = copy.deepcopy(scenePyr)

        #find lines function
        sceneDetected,vectors = self.findLines(sceneDetect)  ### we can use this VECTORS to control
        cv2.imshow("image",sceneDetected)
        cv2.waitKey(0)

def main():
    node = TrackVision()
    img=cv2.imread("track.png")
    node.pixyImageCallback(img)


if __name__ == '__main__':
    main()
