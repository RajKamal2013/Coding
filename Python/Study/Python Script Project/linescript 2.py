# /usr/bin/python
import re, os, sys
#80 character exceeed then new line is done.
#check if line is comment then process it by another way --------------------------------------> to be done.........
#check for the end of line, if word is not completed and 80 is reached handle it ---------------> to be done .......
def line1(filename):
	tempfile="abc123.c";
	fin=open(filename, "r");
	fout=open(tempfile, "w+");
	
	for line in fin:
		string1="";
		string="";
		count=0;
		key=list();
		line_len=0;
		#check if line is comment then process it by another way --------------------------------------> to be done.........
		for word in line:
		#check for the end of line, if word is not completed and 80 is reached handle it ---------------> to be done .......
			c="";
			for char in word:
				count=count+1;
				if(char=="\t"):
					count=count+7;
				if(count >= 80):
					if(char != ';'):
						key.append("\\");
						string1="".join(key);
						string=string1+"\n";
						del key;
						key=list();
						count=1;
					#end of if loop 
					else:
						string1="".join(key);
						del key;
						key=list();
						count=1
				#end of if loop
				key.append(char);
				c=char;
			#end of for loop
		#end of for loop
		if(len(key)>0):
			string1="".join(key);
			string=string + string1;
		#end of if loop
		#print "original->", line;
		#print "new->", string;
		fout.write(string);
		#end of if loop.
	#end of for loop.
	fin.close();
	fout.close();
#end of function

def start():
	length=len(sys.argv);
	for index in range(1,length):
		filename=str(sys.argv[index]);
		line1(filename);
	#end of for loop
#end of start function.

start();
					
	
