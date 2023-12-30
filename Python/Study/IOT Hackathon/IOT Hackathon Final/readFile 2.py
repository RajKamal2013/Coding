import os
path="/Users/rajkamal/Documents/work/Python/Hackathon/"
os.chdir(path)
filename=filepath = os.path.join(os.getcwd(), "readFile.py")
with open(filename,"r") as f:
    contents = f.read()
    print (contents)


