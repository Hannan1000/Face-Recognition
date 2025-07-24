import cv2

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

def process_image(image_data):

    img_array = bytearray(image_data)
    img_np = cv2.imdecode(np.asarray(img_array), cv2.IMREAD_COLOR)


    gray = cv2.cvtColor(img_np, cv2.COLOR_BGR2GRAY)


    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5)

    return len(faces)

ser = serial.Serial('COM3', 9600) 

while True:
    
    if ser.readline().decode('utf-8').strip() == 'CaptureImage':
    
        result = process_image(captured_image_data)

        ser.write((str(result) + '\n').encode('utf-8'))
from math import*
Fs=8000
f=50
sample=16
a=[0]*sample
for n in range(sample):
    a[n]=400*cos(2*pi*f*n/Fs)