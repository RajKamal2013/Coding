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


with open('james.txt') as jaf:
	data = jaf.readline()
james = data.strip().split(',')
with open('julie.txt') as jul:
	data = jul.readline()
julie = data.strip().split(',')
with open('mikey.txt') as mik:
	data = mik.readline()
mikey = data.strip().split(',')
with open('sarah.txt') as sar:
	data = sar.readline()
sarah = data.strip().split(',')

print("James:")
print(james)
print("Julia:")
print(julie)
print("Mikey")
print(mikey)
print("Sarah")
print(sarah)

print("Clean ones")

clean_james = sorted([sanitize(each_t) for each_t in james])
clean_julie = sorted([sanitize(each_t) for each_t in julie])
clean_mikey = sorted([sanitize(each_t) for each_t in mikey])
clean_sarah = sorted([sanitize(each_t) for each_t in sarah])

print("James:")
print(clean_james)
print("Julie:")
print(clean_julie)
print("Mikey")
print(clean_mikey)
print("Sarah")
print(clean_sarah)

unique_james = sorted(set(([sanitize(each_t) for each_t in james])))
unique_julie = sorted(set(([sanitize(each_t) for each_t in julie])))
unique_mikey = sorted(set(([sanitize(each_t) for each_t in mikey])))
unique_sarah = sorted(set(([sanitize(each_t) for each_t in sarah])))

print("James:")
print(unique_james)
print("Julie:")
print(unique_julie)
print("Mikey")
print(unique_mikey)
print("Sarah")
print(unique_sarah)
