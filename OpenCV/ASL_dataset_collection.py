# Import opencv
import cv2 

# Import uuid
import uuid

# Import Operating System
import os

# Import time
import time

key = cv2. waitKey(1)
webcam = cv2.VideoCapture(0)
num_of_images=10
#labels='ABCDEFGHIJKLMNOPQRST'
#labels=list(labels)+['nothing','space']
labels='C'
# Parent Directory path
parent_dir = r"C:\Users\saiva\Desktop\iot_project"
for j in range(len(labels)):
	directory = labels[j] 
	path = os.path.join(parent_dir, directory)
	os.mkdir(path)
	IMAGES_PATH=path
	for label in labels:
		cap = cv2.VideoCapture(0)
		print('Collecting images for {}'.format(label))
		time.sleep(5)
		for imgnum in range(20,20+num_of_images):
			print('Collecting image {}'.format(imgnum))
			ret, frame = cap.read()
			imgname = os.path.join(IMAGES_PATH,label+str(imgnum)+'.jpg')
			cv2.imwrite(imgname, frame)
			cv2.imshow('Frame', frame)
			print("Image location: ",imgname)
			time.sleep(2)

			if cv2.waitKey(1) & 0xFF == ord('q'):
				break
cap.release()
cv2.destroyAllWindows()
