import cv2
import mediapipe as mp
import matplotlib.pyplot as plt
import numpy as np
import math
import scipy
from numpy.lib.function_base import median
from scipy.interpolate import UnivariateSpline

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

def getCoord(image, normalx, normaly):
    image_rows, image_cols, _ = image.shape
    x_px = min(math.floor(normalx * image_cols), image_cols - 1)
    y_px = min(math.floor(normaly * image_rows), image_rows - 1)
    return x_px, y_px

# For webcam input:
drawing_spec = mp_drawing.DrawingSpec(thickness=1, circle_radius=1)
cap = cv2.VideoCapture(0)
overlay = cv2.imread('C:/Users/annie/Downloads/PikPng.com_face-png-transparent_2717214.png')

with mp_face_mesh.FaceMesh(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as face_mesh:
  while cap.isOpened():

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

        left_lip = math.sqrt((chin_anchor_x_val-left_lip_corner_x_val)**2 + (chin_anchor_y_val-left_lip_corner_y_val)**2)
        right_lip = math.sqrt((chin_anchor_x_val-right_lip_corner_x_val)**2 + (chin_anchor_y_val-right_lip_corner_y_val)**2)
        
        left_eye_dist = math.sqrt((left_eyebrow_x_val-left_eye_x_val)**2 + (left_eyebrow_y_val-left_eye_y_val)**2)
        right_eye_dist = math.sqrt((right_eyebrow_x_val-right_eye_x_val)**2 + (right_eyebrow_y_val-right_eye_y_val)**2)

        eye_diff = abs(left_eye_dist - right_eye_dist)/min(left_eye_dist, right_eye_dist)
        
        lip_diff = abs(left_lip - right_lip)/min(left_lip, right_lip)
        
        texted_image = image
        
        if (eye_diff > 0.03):
            texted_image = cv2.putText(img=np.copy(texted_image), text="Mismatched eyebrows", org=(50,50),fontFace=3, fontScale=1, color=(255,255,255), thickness=3)

        # if (lip_diff > 0.11):
        #     texted_image = cv2.putText(img=np.copy(texted_image), text="Drooping lip", org=(50,100),fontFace=3, fontScale=1, color=(255,255,255), thickness=3)

    cv2.imshow('MediaPipe FaceMesh', texted_image)
    if cv2.waitKey(5) & 0xFF == 27:
      break
cap.release()