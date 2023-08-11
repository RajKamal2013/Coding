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


with open('sarah.txt') as sar:
	data = sar.readline()
sarah = data.strip().split(',')

