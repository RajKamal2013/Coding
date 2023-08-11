import pickle

man=[]
other=[]

try:
	data = open('sketch.txt')
	for each_line in data:
		try:
			(role, line_spoken)=each_line.split(':', 1)
			if role=='Man':
				man.append(line_spoken)
			elif role=='Other Man':
				other.append(line_spoken)
		except ValueError as err:
			pass
except IOError as err:
	print('Cant Open! File Missing' + str(err))

finally:
	if data in locals():
		data.close()
	
try:
	man_file = open('man_data.txt', 'w')
	other_file = open('other_data.txt', 'w')
	print(man, file=man_file)
	print(other, file=other_file)
except IOError as err:
	print('File Error' + str(err))
finally:
	if 'man_file' in locals():
		man_file.close()
	if 'other_file' in locals():
		other_file.close()
try:
	with open('man_bin_data.txt', 'wb') as man_file, open('other_bin_data.txt', 'wb') as other_file:
		pickle.dump(man, man_file)
		pickle.dump(other, other_file)
except IOError as err:
	print('File Error' + str(err))
except pickle.PickleError as perr:
	print('Pickel Error' + str(perr))

