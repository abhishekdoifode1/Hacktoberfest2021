import cv2
import mediapipe as mp
import matplotlib.pyplot as plt
import numpy as np
import math
import time
from numpy.lib.function_base import median
from scipy.interpolate import UnivariateSpline
import winsound

mp_drawing_styles = mp.solutions.drawing_styles
mp_drawing = mp.solutions.drawing_utils
mp_face_mesh = mp.solutions.face_mesh

left_lip_corner = 61
right_lip_corner = 91
chin_anchor = 152

left_eyebrow = 105
left_eye = 145
right_eyebrow = 334
right_eye = 374

nose_top = 6
nose_bottom = 4

instr_array = ["Get ready!", "Wrinkle your nose", "Puff your cheeks and blow", "Smile :)"]

wrinkled = False
puff = False
kiss = False
smile = False

def getCoord(image, normalx, normaly):
    image_rows, image_cols, _ = image.shape
    x_px = min(math.floor(normalx * image_cols), image_cols - 1)
    y_px = min(math.floor(normaly * image_rows), image_rows - 1)
    return x_px, y_px

def overlay_image_alpha(img, img_overlay, x, y, alpha_mask):
    """Overlay `img_overlay` onto `img` at (x, y) and blend using `alpha_mask`.

    `alpha_mask` must have same HxW as `img_overlay` and values in range [0, 1].
    """
    # Image ranges
    y1, y2 = max(0, y), min(img.shape[0], y + img_overlay.shape[0])
    x1, x2 = max(0, x), min(img.shape[1], x + img_overlay.shape[1])

    # Overlay ranges
    y1o, y2o = max(0, -y), min(img_overlay.shape[0], img.shape[0] - y)
    x1o, x2o = max(0, -x), min(img_overlay.shape[1], img.shape[1] - x)

    # Exit if nothing to do
    if y1 >= y2 or x1 >= x2 or y1o >= y2o or x1o >= x2o:
        return

    # Blend overlay within the determined ranges
    img_crop = img[y1:y2, x1:x2]
    img_overlay_crop = img_overlay[y1o:y2o, x1o:x2o]
    alpha = alpha_mask[y1o:y2o, x1o:x2o, np.newaxis]
    alpha_inv = 1.0 - alpha

    img_crop[:] = alpha * img_overlay_crop + alpha_inv * img_crop


# For webcam input:
drawing_spec = mp_drawing.DrawingSpec(thickness=1, circle_radius=1)
cap = cv2.VideoCapture(0)
overlay = cv2.imread('C:/Users/annie/Downloads/PikPng.com_face-png-transparent_2717214.png')

timestamp = time.time()
timeelapsed = timestamp
instr_index = 0

mouth_width = 0
new_mouth_width = 0

nose_length = 0
new_nose_length = 0

colr = (255, 255, 255)

with mp_face_mesh.FaceMesh(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as face_mesh:
  while cap.isOpened():

    timeelapsed = time.time()
    
    seconds = 10 - abs(timestamp - timeelapsed)
    
    success, image = cap.read()
    if not success:
      print("Ignoring empty camera frame.")
      # If loading a video, use 'break' instead of 'continue'.
      continue

    # Flip the image horizontally for a later selfie-view display, and convert
    # the BGR image to RGB.
    image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
    cimage = image
    # To improve performance, optionally mark the image as not writeable to
    # pass by reference.
    image.flags.writeable = False
    results = face_mesh.process(image)
    
    # Draw the face mesh annotations on the image.
    image.flags.writeable = True
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    if results.multi_face_landmarks:
      for face_landmarks in results.multi_face_landmarks:
        mp_drawing.draw_landmarks(
            image=image,
            landmark_list=face_landmarks,
            connections=mp_face_mesh.FACEMESH_TESSELATION,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp_drawing_styles
            .get_default_face_mesh_tesselation_style())
        mp_drawing.draw_landmarks(
            image=image,
            landmark_list=face_landmarks,
            connections=mp_face_mesh.FACEMESH_CONTOURS,
            landmark_drawing_spec=None,
            connection_drawing_spec=mp_drawing_styles
            .get_default_face_mesh_contours_style())
                
        chin_anchor_x_val, chin_anchor_y_val = getCoord(image, face_landmarks.landmark[chin_anchor].x, face_landmarks.landmark[chin_anchor].y)
        left_lip_corner_x_val, left_lip_corner_y_val = getCoord(image, face_landmarks.landmark[left_lip_corner].x, face_landmarks.landmark[left_lip_corner].y)
        right_lip_corner_x_val, right_lip_corner_y_val = getCoord(image, face_landmarks.landmark[right_lip_corner].x, face_landmarks.landmark[right_lip_corner].y)
        left_eyebrow_x_val, left_eyebrow_y_val = getCoord(image, face_landmarks.landmark[left_eyebrow].x, face_landmarks.landmark[left_eyebrow].y)
        right_eyebrow_x_val, right_eyebrow_y_val = getCoord(image, face_landmarks.landmark[right_eyebrow].x, face_landmarks.landmark[right_eyebrow].y)
        left_eye_x_val, left_eye_y_val = getCoord(image, face_landmarks.landmark[left_eye].x, face_landmarks.landmark[left_eye].y)
        right_eye_x_val, right_eye_y_val = getCoord(image, face_landmarks.landmark[right_eye].x, face_landmarks.landmark[right_eye].y)
        
        nose_top_x_val, nose_top_y_val = getCoord(image, face_landmarks.landmark[nose_top].x, face_landmarks.landmark[nose_top].y)
        nose_bottom_x_val, nose_bottom_y_val = getCoord(image, face_landmarks.landmark[nose_bottom].x, face_landmarks.landmark[nose_bottom].y)

        left_lip = math.sqrt((chin_anchor_x_val-left_lip_corner_x_val)**2 + (chin_anchor_y_val-left_lip_corner_y_val)**2)
        right_lip = math.sqrt((chin_anchor_x_val-right_lip_corner_x_val)**2 + (chin_anchor_y_val-right_lip_corner_y_val)**2)
        
        left_eye_dist = math.sqrt((left_eyebrow_x_val-left_eye_x_val)**2 + (left_eyebrow_y_val-left_eye_y_val)**2)
        right_eye_dist = math.sqrt((right_eyebrow_x_val-right_eye_x_val)**2 + (right_eyebrow_y_val-right_eye_y_val)**2)

        eye_diff = abs(left_eye_dist - right_eye_dist)/min(left_eye_dist, right_eye_dist)
        
        lip_diff = abs(left_lip - right_lip)/min(left_lip, right_lip)
        
        nose_diff = math.sqrt((nose_top_x_val-nose_bottom_x_val)**2 + (nose_top_y_val-nose_bottom_y_val)**2)
        
        texted_image = image
        
        image = cv2.circle(image, (20,40), 10, color=colr, thickness=5)
        texted_image = cv2.putText(img=np.copy(image), text=str(int(seconds)), org=(50,50),fontFace=3, fontScale=1, color=(255,255,255), thickness=3)
        texted_image = cv2.putText(img=np.copy(texted_image), text=instr_array[instr_index], org=(100,50),fontFace=3, fontScale=1, color=(255,255,255), thickness=3)
        
        if (seconds < 0):
            instr_index+=1
            seconds = 10
            timestamp=time.time()
            timeelapsed = timestamp
            
        new_mouth_width = abs(left_lip_corner_x_val - right_lip_corner_x_val)
        new_nose_length = nose_diff
        
        if (instr_index == 0):
            # winsound.PlaySound("SystemExit", winsound.SND_ALIAS)
            colr = (255,255,255)
            mouth_width = abs(left_lip_corner_x_val - right_lip_corner_x_val)
            nose_length = nose_diff
            
        elif (instr_index == 1 and (nose_length * 1.1) < new_nose_length):
            # alpha = 0.5
            # texted_image = np.uint8(texted_image*alpha + overlay*(1-alpha))
            colr = (0,255,0)
            print("bunny ears")
            
        elif (instr_index == 2 and (mouth_width * 0.9) > new_mouth_width):
            colr = (0,255,0)
            print("firebreath")
            
        elif (instr_index == 3 and (mouth_width * 1.1) < new_mouth_width):
            colr = (0,255,0)
            print("rainbow")
            
        else:
            colr = (0,255,255)
        
    cv2.imshow('MediaPipe FaceMesh', texted_image)
    if cv2.waitKey(5) & 0xFF == 27:
      break
cap.release()