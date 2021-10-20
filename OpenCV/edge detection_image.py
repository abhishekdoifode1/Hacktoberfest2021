import cv2
import matplotlib.pyplot as plt

# 0 to read grayscale
img = cv2.imread('path_to_image',0)
edges = cv2.Canny(img,25,90)

# setting dimensions to resize
width = int(img.shape[1])
height = int(img.shape[0])
dim = (width,height)

edges = cv2.resize(edges,dim)

plt.imshow(edges, cmap='gray')
plt.xticks([])
plt.yticks([])
plt.show()

cv2.imshow("a",edges)
cv2.waitKey(10000)
