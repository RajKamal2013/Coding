#!/usr/local/bin/python3
import athletemodel
import yate
import glob
import pickle

#data_file=['sarah.txt', 'james.txt']
data_file = glob.glob("data/*.txt")
#print(data_file)
athletes= athletemodel.put_to_store(data_file)
#print(athletes)
#athletes = athletemodel.get_from_store()
#print(athletes)


print(yate.start_response())
print(yate.include_header("Coach Kelly's list of athlete"))
print(yate.start_form("generate_timing_data.py"))
print(yate.para("Select an Athlete from the list"))
#print(yate.para("Raj Kamal"))
#print(yate.para("yeah str of athelte" + str(athletes)))
#print(yate.para("data file" + str(data_file)))

for each_athlete in athletes:
	print(yate.para("yeah key  of athelte: " + each_athlete))
	print(yate.para("yeah value of athelte: " + athletes[each_athlete].name))
	print(yate.radio_button("which_athlete", athletes[each_athlete].name))

print(yate.end_form("Select"))
print(yate.include_footer({"Home": "/index.html"}))

