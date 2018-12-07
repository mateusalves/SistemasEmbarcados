import cv2
import os
import sys

cam = cv2.VideoCapture(0)
cam.set(3, 640) #largura do video
cam.set(4, 480) #altura do video

face_detector = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Recebe o id (numero inteiro)  na chamada da função  parametro 1
face_id = sys.argv[1]

print("\n Cadastramento Facial. Por favor, olhe para a câmera e aguarde ...")

# Inicia o contador
count = 0

while(True):

    ret, img = cam.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_detector.detectMultiScale(gray, 1.3, 5)

    for (x,y,w,h) in faces:

        cv2.rectangle(img, (x,y), (x+w,y+h), (255,0,0), 2)
        count += 1

        # Salva a imagem capturada na pasta dataset do mesmo diretorio
        cv2.imwrite("dataset/User." + str(face_id) + '.' + str(count) + ".jpg", gray[y:y+h,x:x+w])

        cv2.imshow('image', img)

    k = cv2.waitKey(100) & 0xff # Pressionar ESC sai do programa
    if k == 27:
        break
    elif count >= 30: # Tira 30 amostras de fotos 
         break

print("\n Finalizando cadastramento, aguarde...")
os.system("python3 02_Treinamento_do_Sistema.py")
cam.release()
cv2.destroyAllWindows()


