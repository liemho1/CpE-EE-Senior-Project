import cv2
import numpy as np
from matplotlib import pyplot as plt

orgImg = cv2.imread('lawn5.png')
grayImg = cv2.imread('lawn5.png',0)
edges = cv2.Canny(grayImg,100,200)

plt.subplot(131),plt.imshow(orgImg)
plt.title('Original'), plt.xticks([]), plt.yticks([])
plt.subplot(132),plt.imshow(grayImg,cmap = 'gray')
plt.title('Gray'), plt.xticks([]), plt.yticks([])
plt.subplot(133),plt.imshow(edges,cmap = 'gray')
plt.title('Edge'), plt.xticks([]), plt.yticks([])

plt.show()