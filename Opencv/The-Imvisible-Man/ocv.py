import cv2
import numpy as np
import time
#harry potter uses that cloak to become invisible 
#color dectection technique and segmentation 
#in greeen screening we remove background in this techniqu we remove the background

# alias python='/Library/Frameworks/Python.framework/Versions/3.6/bin/python3.6'
# replace the pixels corresponding with background pixels to generate the invisibilty feature

#Hue : This channel encodes color information. Hue can be thought of an angle where 0 degree corresponds to the red color, 
#      120 degrees corresponds to the green color, and 240 degrees corresponds to the blue color.
#Saturation : This channel encodes the intensity/purity of color. For example, pink is less saturated than red.
#$Value : This channel encodes the brightness of color. Shading and gloss components of an image appear in this channel
#reading the videocapture video  
print(cv2.__version__)
capture_video = cv2.VideoCapture("video1.mp4")  #Use this statement for show the attached video view....
#cap = cv2.VideoCapture(0) #Use this statement for show the real time view....

#give the camera to warm up
time.sleep(1) 
count = 0 
background = 0 

#capturing the background in range of 60
for i in range(60):
	return_val , background = capture_video.read()
	if return_val == False :
		continue 

background = np.flip(background, axis=1)

# we are reading from video 
while (capture_video.isOpened()):
	return_val, img = capture_video.read()
	if not return_val :
		break 
	count = count + 1
	img = np.flip(img , axis=1)
	# convert the image - BGR to HSV
	# as we focused on detection of red color 
	hsv = cv2.cvtColor(img , cv2.COLOR_BGR2HSV)
	# generating mask to detect red color
	# HSV
	# it should be mono-color cloth 
	# lower range
	lower_red = np.array([100, 40, 40])
	upper_red = np.array([100, 255, 255])
	mask1 = cv2.inRange(hsv,lower_red,upper_red)

	lower_red = np.array([155, 40, 40])
	upper_red = np.array([180, 255, 255])
	mask2 = cv2.inRange(hsv,lower_red,upper_red)

	mask1 = mask1+mask2

    # Refining the mask corresponding to the detected red color
	mask1 = cv2.morphologyEx(mask1, cv2.MORPH_OPEN, np.ones((3,3),np.uint8),iterations=2)
	mask1 = cv2.dilate(mask1,np.ones((3,3),np.uint8),iterations = 1)
	mask2 = cv2.bitwise_not(mask1)

    # Generating the final output
	res1 = cv2.bitwise_and(background,background,mask=mask1)
	res2 = cv2.bitwise_and(img,img,mask=mask2)
	final_output = cv2.addWeighted(res1,1,res2,1,0)

	cv2.imshow("INVISIBLE MAN",final_output)
	k = cv2.waitKey(10)
	if k == 27:
		break