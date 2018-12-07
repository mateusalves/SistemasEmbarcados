#chama a função passando 2 parametros: numero do ID e nome da pessoa
import cv2
import numpy as np
import os
import sys
import time

recognizer = cv2.face.createLBPHFaceRecognizer()
recognizer.load('trainer/trainer.yml')
cascadePath = "haarcascade_frontalface_default.xml"
faceCascade = cv2.CascadeClassifier(cascadePath);

font = cv2.FONT_HERSHEY_SIMPLEX

desconhece = 0
reconhece = 0
id = 0
num_ID = 0

num_ID = int(sys.argv[1])
names = ['None', 'a', 'Mayara', 'c', 'd', 'e'] 
names[num_ID] = sys.argv[2]
names[0] = "Vazio"

cam = cv2.VideoCapture(0)
cam.set(3, 640)
cam.set(4, 480)

#Define a menor janela capaz de ser reconhecida como um rosto
minW = 0.1*cam.get(3)
minH = 0.1*cam.get(4)


while True:

    ret, img =cam.read()

    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor = 1.2,
        minNeighbors = 5,
        minSize = (int(minW), int(minH)),
       )

    for(x,y,w,h) in faces:

        cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)

        id = recognizer.predict(gray[y:y+h,x:x+w])
        if id == num_ID:
             reconhece += 1
        else:
        	    desconhece += 1

        cv2.putText(img, names[num_ID], (x+5,y-5), font, 1, (255,255,255), 2)

    cv2.imshow('camera',img)
   # print (desconhece)

    if reconhece == 30:
    	os.system("./statusLED 1 &")
    	os.system("./movNEMA 12")
    	os.system("./movSERVO &")
    	break
    elif desconhece == 30:
        os.system("./statusLED 0 &");
        cam.release()
        cv2.destroyAllWindows()
        print("\n Pessoa não autorizada...Finalizando reconhecimento")
        chamada = "./buz "+ str(num_ID) + " " + names[num_ID]+" &"
        print (chamada)
        os.system(chamada)
        break
    k = cv2.waitKey(10) & 0xff
    if k == 27:
        break


cam.release()
cv2.destroyAllWindows()
