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

class AthleteList(list):
	def __init__(self, a_name, a_dob=None, a_times=[]):
		self.__init__([])
		self.name = a_name
		self.dob = a_dob
		self.extend(a_times)

	def top3(self):
		return(sorted(set([sanitize(t) for t in self.times]))[0:3])



