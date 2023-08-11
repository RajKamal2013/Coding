#! /usr/bin/python
import re,sys
str1=raw_input("Enter the filename:");
print "The file name entered is :", str1; 

str2="temp";

fin=open(str1,"r");
fout=open(str2,"w");
fin.seek(0);
fout.seek(0);
joiner=" "
for line in fin:
#	print line;
	y=re.findall("enum .*",line);
	if(len(y)>0):
		print y;
		str3=joiner.join(y);
		str3="typedef"+" "+str3;
		print str3;
	fout.write(line);

fin.close();
fout.close();

