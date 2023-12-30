#! /usr/bin/python

str1=raw_input("File Name:");
print "Filename is :",str1;

fin=open(str1,"r");
str2='';
for line in fin:
	str2=str2+" "+line;
#print str2;
n=str2.count("enum",0,len(str2));
print "count-->",n,"\n";

print str2.find("enum",0,len(str2));


