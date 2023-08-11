#!/usr/local/bin/python3
import pickle
from athletelist import AthleteList
import yate

def get_coach_data(filename):
    try:
        with open(filename) as f:
            data = f.readline()
        templ = data.strip().split(',')
        return(AthleteList(templ.pop(0), templ.pop(0), templ))
    except IOError as ioerr:
        print('File error (get_coach_data): ' + str(ioerr))
        return(None)

def put_to_store(files_list):
	all_athletes = {}
	for each_file in files_list:
		ath = get_coach_data(each_file)
		all_athletes[ath.name] = ath
	try:
		with open('athletes.pickle', 'wb') as athf:
			pickle.dump(all_athletes, athf)
			print(yate.para("Doing Pickel"))
		#athf=open('athletes.pickle', 'wb')
		#pickle.dump(all_athletes, athf)
		#athf.close()
	except IOError as ioerr:
		print('File error (put_and_store): ' + str(ioerr))

	return(all_athletes)

def get_from_store():
    all_athletes = {}
    try:
        with open('athletes.pickle', 'rb') as athf:
            all_athletes = pickle.load(athf)
    except IOError as ioerr:
        print('File error (get_from_store): ' + str(ioerr))
    return(all_athletes)

#file_name=['sarah.txt', 'james.txt', 'julie.txt']
#put_to_store(file_name)
