import cv2
import numpy as np

img = cv2.imread('watch.jpg', cv2.IMREAD_COLOR)

cv2.line(img, (0,0), (150,150), (255,255,255), 5)
cv2.rectangle(img, (15,25), (100,140), (255,255,0), 5)
cv2.circle(img, (100,63), 55, (0,0,255), -1)

pts = np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)
#pts = pts.reshape((-1,1,2))
cv2.polylines(img, [pts], False, (0,255,255), 9) 

font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img, 'Ashish', (0,130), font, 5, (255,255,255), 2, cv2.LINE_AA)

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()