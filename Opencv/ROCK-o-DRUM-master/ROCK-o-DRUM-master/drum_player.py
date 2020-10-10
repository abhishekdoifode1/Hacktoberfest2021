import cv2                             #importing modules
import numpy as np
from drum_styles import draw,drum_press 
cap=cv2.VideoCapture(0)
while True:
    ret,frame=cap.read()               #accessing the frames
    frame=cv2.flip(frame,1)
    frame=cv2.GaussianBlur(frame,(9,9),0)
    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    #_, binary = cv2.threshold(gray, 225, 255, cv2.THRESH_BINARY_INV)
    
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)  #converting to Hue_Saturation_Vue format
    #mask=cv2.inRange(hsv,lower_red,upper_red)
    #kernel=np.ones((5,5),np.float32)/25
    #mask=cv2.filter2D(mask,-1,kernel)
    #mask=cv2.blur(mask,(3,3))
    draw(frame)                                #creating the rectangular drums
    kernel1=np.ones((4,4),np.uint8)             #kernels for smoothing the frames
    kernel2=np.ones((15,15),np.uint8)
    lower_red=np.array([132,90,120])           #creating the mask for red color
    upper_red=np.array([179,255,255])
    mask1=cv2.inRange(hsv, lower_red,upper_red)
    
    lower_red=np.array([0,110,100])
    upper_red= np.array([3,255,255])
    mask2=cv2.inRange(hsv, lower_red,upper_red)
    mask_r=mask1+mask2                           #final red mask
    
    mask_r=cv2.erode(mask_r,kernel1,iterations = 1)
    mask_r=cv2.morphologyEx(mask_r,cv2.MORPH_CLOSE,kernel2)
    xr,yr,wr,hr=0,0,0,0
    
    contours_r,hierarchy=cv2.findContours(mask_r,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)  #getting the contours in the mask
    
    
    try:          
      for i in range (0,10):
            xr,yr,wr,hr=cv2.boundingRect(contours_r[i])
            if(wr*hr)>2000:                       #checking for a proper area to avoid noisy disturbances
                  break

    except:
          pass                                     #passes if no maks are there in the image
    
    
       
    lower_b=np.array([38,86,0])                   #blue color range
    upper_b= np.array([121,255,255])
    mask_b=cv2.inRange(hsv, lower_b,upper_b)      #final blue mask
                              
    
    mask_b=cv2.erode(mask_b,kernel1,iterations=1)
    mask_b=cv2.morphologyEx(mask_b,cv2.MORPH_CLOSE,kernel2)
    xb,yb,wb,hb=0,0,0,0
    
    contours_r,hierarchy=cv2.findContours(mask_b,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)  #getting the contours in the mask
    
    
    try:          
      for i in range (0,10):
            xb,yb,wb,hb=cv2.boundingRect(contours_r[i])  #getting the coordinates of the contour
            if(wb*hb)>2000:                       #checking for a proper area to avoid noisy disturbances
                  break

    except:
          pass              
      
    cv2.rectangle(frame,(xr,yr),(xr+wr,yr+hr),(255,255,255),2)   #drawing a rectangle around the red object
    cv2.rectangle(frame,(xb,yb),(xb+wb,yb+hb),(255,255,255),2)
    drum_press(frame,xr,yr,wr,hr)        #checking the drums it hits
    drum_press(frame,xb,yb,wb,hb)
    frame=cv2.resize(frame,(800,600))
    cv2.imshow('ROCK-o-DRUM',frame)  #displaying the frames
    #cv2.imshow('MASK_red',mask)
    
    
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()