# This file will walk through the files in the local file system and
#   1. Creates Cpvbn for L0
#   2. Puts the CPVBN in L1
#   3. Create Blobs for L0 and L1
#   4. Writes these two Blobs to Azure

from lib.blob_api import *
from lib.incore_struct import *

path = '/Users/makam/ws/iot_hackathon/fsdata'
dst_path = '/Users/makam/ws/iot_hackathon/fsdata/read_from_blob'

def main():

    cpvbnObj = CloudPvbn()
    blobStore = C2CBlobStore()

    for root, directories, filenames in os.walk(path):
        print(root)
        print(directories)
        print(filenames)
        for directory in directories:
            directory_path = os.path.join(root, directory)
            print ("Directory ->", directory_path)
            continue
        for filename in filenames:
            file_path = os.path.join(root, filename)
            print ("File ->", file_path)

            with open(file_path, "r") as f:
                contents = f.read(4096)
                l0Header = "L0"
                l1Header = "L1"

                l0PVBN = cpvbnObj.getNextCPvbn()

                l0CloudObj = S2CObjectOnDisk()
                l0CloudObj.S2CObjectHdr[0] = l0Header
                l0CloudObj.S2CObjectData[0] = contents

                print (l0CloudObj.S2CObjectData[0])
                print (l0CloudObj.S2CObjectData[1])
                l1PVBN = cpvbnObj.getNextCPvbn()

                l1CloudObj = S2CObjectOnDisk()

                print(len(l0CloudObj.S2CObjectData[0]))
                arr = bytes(contents,"utf-8")
                print(arr)
                blobStore.writeToBlob("l0", arr)

                blobStore.listBlobs()

                blobStore.getBlob("l0", "/Users/makam/ws/ex")
# Main Method
if __name__ =='__main__':
    main()