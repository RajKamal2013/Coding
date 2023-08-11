def sanitize(time_string:str)->str:
	"""convert a number into decimal format"""
	if '-' in time_string:
		splitter='-'
	elif ':' in time_string:
		splitter=':'
	else:
		return(time_string)
	(minutes, seconds)=time_string.split(splitter)
	return (minutes+'.'+ seconds)

class Athlete:
	def __init__(self, a_name, a_dob=None, a_times=[]):
		self.name = a_name
		self.dob = a_dob
		self.times = a_times

	def top3(self):
		return(sorted(set([sanitize(t) for t in self.times]))[0:3])

def get_coach_data(filename):
	try:
		with open(filename) as f:
			data=f.readline()
		temp1 = data.strip().split(',')
		return (Athlete(temp1.pop(0), temp1.pop(0), temp1))
	except IOError as err:
		print ('File error :' + err)
		return (None)

james = get_coach_data('james2.txt')
print(james.name + "is fastest times are" + str(james.top3()))
#print(james.name)


