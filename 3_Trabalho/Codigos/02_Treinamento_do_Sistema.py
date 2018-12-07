import cv2
import numpy as np
from PIL import Image
import os

# Caminho da pasta de imagens
path = 'dataset'

recognizer = cv2.face.createLBPHFaceRecognizer()
detector = cv2.CascadeClassifier("haarcascade_frontalface_default.xml");


def getImagesAndLabels(path):

    imagePaths = [os.path.join(path,f) for f in os.listdir(path)]
    faceSamples=[]
    ids = []

    for imagePath in imagePaths:

        PIL_img = Image.open(imagePath).convert('L')
        img_numpy = np.array(PIL_img,'uint8')

        id = int(os.path.split(imagePath)[-1].split(".")[1])
        faces = detector.detectMultiScale(img_numpy)

        for (x,y,w,h) in faces:
            faceSamples.append(img_numpy[y:y+h,x:x+w])
            ids.append(id)

    return faceSamples,ids

print ("\n Treinando o sistema para o reconhecimento ...")
faces,ids = getImagesAndLabels(path)
recognizer.train(faces, np.array(ids))

# Salva o modelo dentro de trainer.yml
recognizer.save('trainer/trainer.yml')

# Informa a quantidade de faces trainadas e termina o programa
print("\n  {0} faces foram reconhecidas.".format(len(np.unique(ids))))
