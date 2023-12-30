from datetime import datetime 
import time
import random
odds = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59]

def search4Vowels(word:str='rajkamal') -> set :
	""" This function find out vowels present in word !"""
	vowels = set('aeiou')
	found = vowels.intersection(set(word))
	result = found
	return (found)

def Search4Letters(phrase:str = 'rajkamal', letters:str='aeiou') -> set :
	"""Function searches for occurances of letters in phrase"""
	return set(letters).intersection(set(phrase))

def Speak4Time():
	""" This will time is odd or even"""
	for i in range(5):
		right_this_minute = datetime.today().minute

		if right_this_minute in odds:
			print ("This minute seems little odd")
		else:
			print ("This minute is even")

		wait_time = random.randint(1, 10)
		time.sleep(wait_time)

