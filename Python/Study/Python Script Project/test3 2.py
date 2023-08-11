#! /usr/bin/python 

str=raw_input("Enter the string:");
list1=str.split();
#print list1;
n=len(list1);
for  i in range(0,n):
	print list1[i],"\n";
#print list1[2];

str2=" ".join(list1);
print str2, "\n";

