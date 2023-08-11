import os

path = '/Users/rajkamal/'

for root, directories, filenames in os.walk(path):
    for directory in directories:
        directory_path = os.path.join(root, directory)
        print ("Directory ->", directory_path)
        for filename in filenames:
            file_path = os.path.join(root,filename)
            print ("File ->", file_path)

