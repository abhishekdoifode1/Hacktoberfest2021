import cv2
import numpy as np
import time
import pose_estimation_module as pem

#####################
wCam, hCam = 780, 480
#####################

cap = cv2.VideoCapture('Projects/PoseEstimation/Resources/curls.mp4')
detector = pem.poseDetector()
pTime = 0
count, dir = 0, 0

# fourcc = cv2.VideoWriter_fourcc(*'XVID')
# out = cv2.VideoWriter('output.avi', fourcc, 20.0, (640, 480))

while True:
    success, img = cap.read()
    img = cv2.resize(img, (wCam, hCam), interpolation=cv2.INTER_AREA)
    img = detector.findPose(img, False)
    lmList = detector.findPosition(img, False)
    # print(lmList)

    if len(lmList) != 0:
        # Right arm
        # detector.findAngle(img, 12, 14, 16)

        # Left arm
        angle = detector.findAngle(img, 11, 13, 15)
        per = np.interp(angle, (210, 310), (0, 100))
        # print(angle, per)

        # Check for dumbell curls
        if per == 100:
            if dir == 0:
                count += 0.5
                dir = 1
        if per == 0:
            if dir == 1:
                count += 0.5
                dir = 0

        cv2.rectangle(img, (20, int(400-per*2.5)), (40, 400),
                      (0, 255, 0), cv2.FILLED)
        cv2.putText(img, f'{int(per)}%', (20, 120),
                    cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 0), 2)
        cv2.putText(img, f'Count: {int(count)}', (20, 70),
                    cv2.FONT_HERSHEY_PLAIN, 2, (200, 55, 100), 2)

    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime
    cv2.putText(img, f'FPS: {int(fps)}', (20, 40),
                cv2.FONT_HERSHEY_PLAIN, 2, (200, 55, 100), 2)
    cv2.putText(img, f'@RaflyNagachi', (20, 460),
                cv2.FONT_HERSHEY_PLAIN, 1.5, (0, 255, 100), 1)
    cv2.rectangle(img, (20, 150), (40, 400), (0, 255, 0), 2)
    # out.write(img)
    cv2.imshow('Images', img)

    if cv2.waitKey(0) == ord('q'):
        break

# out.release()
cap.release()
cv2.destroyAllWindows()
