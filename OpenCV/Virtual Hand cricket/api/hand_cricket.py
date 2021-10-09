import cv2
import numpy as np
import math
import random
import imutils
from time import sleep
global player_score
global bot_score
key=''
global player
global bot

player_status = False
bot_status = False
Game_status = "Player Begins"
def check_status(player_score, bot_score):
    if player_score > bot_score:
        print('* * * Player wins * * *')

    else:
        print('* * *   Bot wins  * * *')
        

       

class VideoCamera(object):
    def __init__(cap):
        #real time video capture
        cap.video = cv2.VideoCapture(0)
    def __del__(cap):
        cap.video.release()
        
        
    def get_frame(cap, key):
        ret, frame = cap.video.read()
        frame=cv2.flip(frame,1)
        #frame = imutils.resize(frame, width=1000,height=600)
        kernel = np.ones((3,3),np.uint8)
                 
        #define region of interest
        img=frame[100:500, 100:500]
        
        cv2.rectangle(frame,(100,100),(500,500),(0,255,0),2)    
        cv2.putText(frame,"Put hand in the box", (90,90), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        
        player_score=0
        bot_score = 0

        player = False
        bot = True
        
        player_status = False
        bot_status = False
        Game_status = "Player Begins" 
        #scoreboard
        # score=cv2.imread('D:/HackBattle/black.jpg')
        # score= cv2.putText(score,"Scoreboard", (90,10), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0,255,0))
        # score= cv2.line(score, (0,15), (500,15), (0,255,0), 1)
        # score= cv2.line(score, (140,20), (140,60), (0,255,0), 1)
        # score= cv2.putText(score,"Player", (90,50), cv2.FONT_HERSHEY_SIMPLEX, 0.45, (0,255,0))
        # score= cv2.putText(score,"Bot", (160,50), cv2.FONT_HERSHEY_SIMPLEX, 0.45, (0,255,0))
        # score= cv2.putText(score,"Match is of 3 Overs", (70,30), cv2.FONT_HERSHEY_SIMPLEX, 0.4, (0,255,155))
        
        
        # define range of skin color in HSV
        lower_skin = np.array([0, 20, 80], dtype=np.uint8)
        upper_skin = np.array([20,255,255], dtype=np.uint8)
        
        #extract skin colur imagw  
        mask = cv2.inRange(hsv, lower_skin, upper_skin)
        
        #extrapolate the hand to fill dark spots within
        mask = cv2.dilate(mask,kernel,iterations = 4)
        
        #blur the image
        mask = cv2.GaussianBlur(mask,(5,5),100) 
        
        #find contours
        contours,hierarchy= cv2.findContours(mask,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
          
        #find contour of max area(hand)
        if len(contours) > 0:
            #find contour of max area(hand)
            areas = [cv2.contourArea(c) for c in contours]
            max_index = np.argmax(areas)
            cnt = contours[max_index]
        
        #cv2.drawContours(frame, cnt, -1, (0,0,255), 3)
        
        #approx the contour a little
        epsilon = 0.0005*cv2.arcLength(cnt,True)
        approx= cv2.approxPolyDP(cnt,epsilon,True)
           
        #make convex hull around hand
        hull = cv2.convexHull(cnt)
        
        #define area of hull and area of hand
        areahull = cv2.contourArea(hull)
        areacnt = cv2.contourArea(cnt)
          
        #find the percentage of area not covered by hand in convex hull
        arearatio=((areahull-areacnt)/areacnt)*100
        #print(arearatio)
        
        
        #find the defects in convex hull with respect to hand
        hull = cv2.convexHull(approx, returnPoints=False)
        defects = cv2.convexityDefects(approx, hull)
        #print(defects)
        
        #sleep(2)
        # l = no. of defects
        count_defect=0
        

        
        #code for finding no. of defects due to fingers
        for i in range(defects.shape[0]):
            s,e,f,d = defects[i,0]
            start = tuple(approx[s][0])
            end = tuple(approx[e][0])
            far = tuple(approx[f][0])
            
            # find length of all sides of triangle
            a = math.sqrt((end[0] - start[0])**2 + (end[1] - start[1])**2)
            b = math.sqrt((far[0] - start[0])**2 + (far[1] - start[1])**2)
            c = math.sqrt((end[0] - far[0])**2 + (end[1] - far[1])**2)
            
            # apply cosine rule here
            angle = math.acos((b**2 + c**2 - a**2)/(2*b*c)) * 57
            #print(angle)
            
        
            # ignore angles > 90 
            if angle <= 90:
                count_defect += 1
                cv2.circle(img, far, 5, (255,0,0), -1)
            
            #draw lines around hand
            cv2.line(img,start, end, (255,0,0), 3)
            
        count_defect += 1
        
        player_num = count_defect
        if  key == 'h'or 0xFF==ord('h'):
            
            
            #print corresponding gestures which are in their ranges
            font = cv2.FONT_HERSHEY_SIMPLEX
        
            if count_defect==1:
                if arearatio<15:
                    cv2.putText(frame,'0',(0,50), font, 2, (255,0,0), 3, cv2.LINE_AA)    
                else:
                    cv2.putText(frame,'1',(0,50), font, 2, (255,0,0), 3, cv2.LINE_AA)
                        
            elif count_defect==2:
                cv2.putText(frame,'2',(0,50), font, 2, (255,0,0), 3, cv2.LINE_AA)
                
            elif count_defect==3:
                cv2.putText(frame,'3',(0,50), font, 2, (255,0,0), 3, cv2.LINE_AA)
                            
            elif count_defect==4:
                cv2.putText(frame,'4',(0,50), font, 2, (255,0,0), 3, cv2.LINE_AA)
                
            elif count_defect==5:
                cv2.putText(frame,'5',(0,50), font, 2, (255,0,0), 3, cv2.LINE_AA)
                
            if player is False: # i.e. player will bat first
                    #print('Player will bat !') 
                    bot_num = random.randint(0,5)
                   
                    if player_num == bot_num:
                        print('Player {} - Bot {} #1'.format(player_num, bot_num), end=' ')
                        cv2.putText(frame,"player_score:{}".format(str(player_num)), (10,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
                        cv2.putText(frame,"bot_score:{}".format(str(bot_num)), (500, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
    
                        # score=cv2.putText(score,"Player is out!", (90,85), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
                        # score= cv2.putText(score,"Bot will bat now!", (90, 105), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
                        player_status = True
                        player = True
                        bot = False
                        
                    else:
                        player_score += player_num
                        print('Player {} - Bot {} #2'.format(player_num, bot_num))
                        cv2.putText(frame,"player_score:{}".format(str(player_num)), (10,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
                        cv2.putText(frame,"bot_score:{}".format(str(bot_num)), (500, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
                        print('Player score: {}'.format(player_score))
                        # text="Player score: ".join(str(player_score()))
                        # score= cv2.putText(score,text,(90, 105), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
                        
            
            
            elif bot is False: # i.ie if player is out, bot will bat
                    bot_num = random.randint(0,5)
            
                    if bot_num == player_num:
                        print('{} - {} #3'.format(bot_num, player_num), end=' ')
                        cv2.putText(frame,"player_score:{}".format(str(player_num)), (10,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
                        cv2.putText(frame,"bot_score:{}".format(str(bot_num)), (500, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
    
                        # score= cv2.putText(score,"Bot is out!",(90, 120), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
                        # bot_status = True
                        print('Final score of Bot: {}'.format(bot_score))  

                        check_status(player_score, bot_score)
                        
                    else:
                        bot_score += bot_num
                        print('Bot_num {} - Player_num {} #4'.format(bot_num, player_num))
                        cv2.putText(frame,"player_score:{}".format(str(player_num)), (10,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
                        cv2.putText(frame,"bot_score:{}".format(str(bot_num)), (500, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
    
                        # score= cv2.putText(score,'Bot score: {}',(170, 125), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
                    
        # play_sc=str(player_score)
        # bot_sc= str(bot_score)
        # score= cv2.putText(score,play_sc, (90,70), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
        # score= cv2.putText(score,bot_sc, (160,70), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255,0,0))
        cv2.putText(frame,"player_score:{}".format(str(player_score)), (10,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
        cv2.putText(frame,"bot_score:{}".format(str(bot_score)), (500, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
        
        if player_status == True:           
            Game_status="PLAYER OUT !"
            # print(Game_status)
            cv2.putText(frame,"Game_status:{}".format(str(Game_status)), (500, 200), cv2.FONT_HERSHEY_SIMPLEX, 2.75, (0,255,0), 4)
            # if bot_status == False:
            #     Game_status="Bot will bat now!"                                   
            #     # print(Game_status)
            #     cv2.putText(frame,"Game_status:{}".format(str(Game_status)), (500, 250), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
        if bot_status == True:           
            Game_status="BOT OUT !"                 
            # print(Game_status)
            cv2.putText(frame,"Game_status:{}".format(str(Game_status)), (500, 300), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
            if player_score > bot_score:
                Game_status="Player wins the game ....."
                # print(Game_status)
                cv2.putText(frame,"Game_status:{}".format(str(Game_status)), (500, 350), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
            else:
                Game_status="Bot wins the game ....."
                # print(Game_status)                
                cv2.putText(frame,"Game_status:{}".format(str(Game_status)), (500, 400), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0), 4)
        #show the windows
        #cv2.imshow('mask',mask)
        # cv2.imshow('frame',frame)  
        # cv2.imshow('score',score)    
        # k = cv2.waitKey(10) & 0xFF
        # if k == 27:
        #     break
        
        # cv2.destroyAllWindows()
        # cap.release() 

        ret, jpeg_f = cv2.imencode('.jpg', frame)
        return jpeg_f.tobytes()
    # def score_calc(cap):
           
    #     return player_score, bot_score, player, bot, player_status, bot_status, Game_status
