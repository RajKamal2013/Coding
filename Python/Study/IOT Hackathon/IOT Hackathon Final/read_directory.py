import os

path = 'C:/Users/vinaykub/Documents/Linux'

def files(path):
    for file in os.listdir(path):
        if os.path.isfile(os.path.join(path, file)):
            yield file

for file in files(path):
    print (file)
