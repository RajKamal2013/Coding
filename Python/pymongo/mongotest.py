
from pymongo import MongoClient, errors

def testconnect():
    USERNAME = "root"
    PASSWORD = "root123"
    PORT='27017'
    try:
        client = MongoClient('mongodb://'+USERNAME+':'+ PASSWORD+'@localhost:'+PORT+'/')
        database_names = client.list_database_names()
        print(database_names)
    except errors.ServerSelectionTimeoutError as err:
        client = None
        database_names = []
        print("Could not Connect Database: Pymongo Error:", err)


testconnect()
