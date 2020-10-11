import cv2
import pygame
import time
pygame.init()

x1,y1= 10,10   #coordinates for the drums
x2,y2=100,300
x3,y3=465,10
x4,y4=365,300
w,h=160,160

def draw(frame): 
    cv2.rectangle(frame,(x1,y1),(x1+w,y1+h),(0,255,0),2)     #drawing the drums
    cv2.rectangle(frame,(x2,y2),(x2+w,y2+h),(255,255,0),2)
    cv2.rectangle(frame,(x3,y3),(x3+w,y3+w),(255,0,255),2)
    cv2.rectangle(frame,(x4,y4),(x4+w,y4+w),(66,212,245),2)
    
def drum_press(frame,x,y,w1,h1):
    if x>x1 and y>y1 and x+w1<x1+w and y+h1<y1+h:               #checking which drum it collided with
        cv2.rectangle(frame,(x1,y1),(x1+w,y1+h),(0,255,0),-1)
        pygame.mixer.Sound('crash_c.wav').play()                #playing the .wav file
        time.sleep(0.08)
        pygame.mixer.Sound('crash_c.wav').stop()
            
    elif x>x2 and y>y2 and x+w1<x2+w and y+h1<y2+h:    
        cv2.rectangle(frame,(x2,y2),(x2+w,y2+h),(255,255,0),-1)
        pygame.mixer.Sound('kick02_c.wav').play()
        time.sleep(0.08)
        pygame.mixer.Sound('kick02_c.wav').stop()
        
        
    elif x>x3 and y>y3 and x+w1<x3+w and y+h1<y3+h:    
        cv2.rectangle(frame,(x3,y3),(x3+w,y3+h),(255,0,255),-1)
        pygame.mixer.Sound('rim_c.wav').play()
        time.sleep(0.08)
        pygame.mixer.Sound('rim_c.wav').stop()
        
    elif x>x4 and y>y4 and x+w1<x4+w and y+h1<y4+h:    
        cv2.rectangle(frame,(x4,y4),(x4+w,y4+h),(66,212,245),-1)
        pygame.mixer.Sound('snrbuzz_c.wav').play()
        time.sleep(0.08)
        pygame.mixer.Sound('snrbuzz_c.wav').stop()
        
        