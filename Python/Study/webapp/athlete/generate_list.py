#!/usr/local/bin/python3
import athletemodel
import yate
import glob

data_file = glob.glob("data/*.txt")
#print(data_file)
athletes= athletemodel.put_to_store(data_file)


print(yate.start_response())
print(yate.include_header("Coach Kelly's list of athlete"))
print(yate.start_form("generate_timing_data.py"))
print(yate.para("Select an Athlete from the list"))

for each_athlete in athletes:
	print(yate.radio_button("Which athlete", athletes[each_athlete]['Name']))
	#print(athletes[each_athlete])

print(yate.end_form("Select"))
print(yate.include_footer({"Home": "/index.hmtl"}))

