#! /usr/bin/python
import re
str1='''X-Sieve: CMU Sieve 2.3\
	X-DSPAM-Result: Innocent\
	X-DSPAM-Con.dence: 0.8475\
	X-Content-Type-Message-Body: text/plain'''
fin = open("temp.txt", "r");
str2='';
for line in fin:
	str2=str2+line+'\n';
	if re.search("^X.+:",line):
		print line;

print "original line";
print str2;

y=re.findall("[0-9]+",str2);
print y;
y=re.findall("^X-.*?:",str2);
print y;

str3="From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008"
y=re.findall("\S+@+\S+",str3);
print y;
y=re.findall("[^ ]+",str3);
print y;
y=re.findall("^From.*@([^ ]+)",str3);
print y;
