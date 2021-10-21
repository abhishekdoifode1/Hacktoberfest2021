import cv2

import mediapipe as mp
import numpy as np
import pyautogui
mp_drawing = mp.solutions.drawing_utils
mp_hands = mp.solutions.hands

tipIds = [4, 8, 12, 16, 20]
state = None
Gesture = None
wCam, hCam = 720, 640
instr_array = ["Get ready!", "9 more times to go", "8 more times to go", "8 more times to go", "7 more times to go", "6 more times to go", "5 more times to go", "4 more times to go", "3 more times to go", "2 more times to go", "1 more times to go", "Smile :)"]
instr_index = 0

def fingerPosition(image, handNo=0):
    lmList = []
    if results.multi_hand_landmarks:
        myHand = results.multi_hand_landmarks[handNo]
        for id, lm in enumerate(myHand.landmark):
   
            h, w, c = image.shape
            cx, cy = int(lm.x * w), int(lm.y * h)
            lmList.append([id, cx, cy]) 
    return lmList

cap = cv2.VideoCapture(0)
cap.set(3, wCam)
cap.set(4, hCam)
i = 0

with mp_hands.Hands(
    min_detection_confidence=0.8,
    min_tracking_confidence=0.5) as hands:
  while cap.isOpened():
    success, image = cap.read()
    if not success:
        print("Ignoring empty camera frame.")

        continue

    image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
    image.flags.writeable = False
    results = hands.process(image)
    

    image.flags.writeable = True
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    if results.multi_hand_landmarks:
      for hand_landmarks in results.multi_hand_landmarks:
        mp_drawing.draw_landmarks(
            image, hand_landmarks, mp_hands.HAND_CONNECTIONS)
    lmList = fingerPosition(image)
    imageText = image.copy()

    if len(lmList) != 0:
        


        
        imageText = cv2.putText(img=np.copy(image), text=instr_array[instr_index], org=(50,50),fontFace=3, fontScale=1, color=(255,255,255), thickness=3)
                
        fingers = []
        for id in range(1, 5):
            if lmList[tipIds[id]][2] < lmList[tipIds[id] - 2][2]:
          
                fingers.append(1)
            if (lmList[tipIds[id]][2] > lmList[tipIds[id] - 2][2] ):
         
                fingers.append(0)
        totalFingers = fingers.count(1)
        print(totalFingers)

        
        if totalFingers == 4:
            state = "open"
        # fingers.append(1)
        if totalFingers == 0 and state == "open":
            state = "close"
            instr_index+=1
                
              
                
                

    
        
    cv2.imshow("Media Controller", imageText )
    key = cv2.waitKey(1) & 0xFF

    if key == ord("q"):
        break
  cv2.destroyAllWindows()