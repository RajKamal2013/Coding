#! /usr/bin/python
import re,sys,os
#enum , struct done..
#----------------------space issue check plus multiple line comment 143, 153, 252.-------------------------

#Global Variables
"""dictionary to maintain old string and new string.
	later old string is replaced by new string"""
dict1={};
dict2={};
"""maintains count of dictionary entry"""
count1=0;
count2=0;
"""list to maintain the key of the dictionary"""
key1=list();
key2=list();
"""Temporary files which are deleted at the end"""
tempfilename1="abc123.h";
tempfilename2="abcxyz.h";
"""
1.original file cpoied with changes to tempfilename1 
2.tempfilename2 is copied along with changes to  tempfilename2
3.delete original file
4.tempfilename2 is rename to original file."""
#end of defining global variable.


#Removes temporary files and restores the original file.
def fini(filename):
	#to make gloabal variable in this scope.
	global tempfilename1, tempfilename2;
	os.remove(filename);
	os.remove(tempfilename1);
	os.rename(tempfilename2, filename);
#end of the fucntion fini().

"""
Replaces occurances of the enum, struct var_name in comment, function 
arguments and other places except declaration by var_name_t.
eg. enum/struct var_name ---> var_name_t.
and read from tempfilename1 and write to tempfilename2 after replacing."""
def replace_others():
	#for src, target in dict2.iteritems():
	#	print list2[src], "-->", target;
	#to make gloabal variable visible in function
	global tempfilename1, tempfilename2, dict2, key2; 
	#open the two file to read and write repectively.
	fin=open(tempfilename1, "r+");
	fout=open(tempfilename2, "w+");
	
	#iterate line by line in the file for search and replace
	for line in fin:
		#iterate through the dictioanry for the serching key in line
		for src, target in dict2.iteritems():
			#search for the all enums,struct except the declaration 
			z=re.findall(str(target[0]), line);
			#search for the all enums,struct in value of key src
			y=re.findall("enum ([^ ]*)", str(target[0]));
			#if found enum/struct in line
			if(len(z)>0):
				old_string=str(target[0]); 
				new_string=str(y[0])+"_t";
				line=line.replace(old_string, new_string);
			#end of if loop.
	
		#end of for loop.

		#copy the line to the tempfile
		fout.write(line);
	#end of for loop.

	#closing the open files.
	fin.close();
	fout.close();
#end of the function replace_others()

"""
This function will replace the only declaration of "enum/struct varname {" and
"};" to "typedef enum/struct" and "} var_name_t;"only.
The old string and the new string are found in dictionary variable.
Read from filename and copy that after replacing to tempfilename1"""		
def replace_declaration(filename):
	#now global variable are visible inside function.
	global tempfilename1, key1, dict1;
	#open files to read from and write into.
	fin=open(filename, "r+");
	fout=open(tempfilename1, "w+");
	fin.seek(0);
	fout.seek(0);
	
	#iterate through the file for searching
	for line in fin:
		"""iterate through the dictionary for the searching key
		replacing it with value."""
		for src, target in dict1.iteritems():
			line=line.replace(key1[src], target);
		#end of second for loop
		
		#write to temp file after editing.
		fout.write(line);
	#end of for loop.
	
	fin.close();
	fout.close();
#end of function replace_declaration().
	
"""This function will store all the old string and the new string 
in dictionary. enum var_name { as  key -> enum/struct var_name and 
value -> typedef enum/struct.
The key value are then used to replace by other functions"""
def initialize(old_string, new_string, filename):
	#now global variables are in the scope
	global dict1, key1, count1;
	#it is used to remember the var in enum/struct var
	var_name=list();
#	open the file and bring the file pointer to beginning.
        fin=open(filename,"r");
        fin.seek(0);
#	set n=-1 so that we can set to 1 first time old_string appears
        n=-1;
#	iterate through the file line by line. 
        for line in fin:
		#till the first occurance of old_String is detected.
                if(n==-1):
			#searcing for old_string in line
                        y=re.findall("^"+old_string, line);
			#if old string is found, the length will be positive
			#set the n=1 indicating first occurance is found.
                        if(len(y)>0):
				#print "start->";
				#print line;
                                n=1; 
				var_name = old_string.split (" ");
				#print "varname->", var_name;
				#print "old_string->", old_string;
				#print "new_string->", new_string;
				#set key value pair in dictionary.
				key1.insert(count1, line);
				dict1[count1] = new_string + "{" + "\n";
				count1=count1+1;
			#end of if loop for setting n.

		#end of if loop for checking first occurance
		
		#check that the end of the enum/struct that is the closing 
		#bracket followed by semicolon is seen eg };. """
                elif(n==0) :
			#print the final line for debugging.
                        #print "End->",line1+line
                        break;
		#end of elif loop.
		
		#check for opening and closing bracket in the line and
		#increment and decreament the count of n based on brackets.
		#If line is a comment then don't increament or decreament count
		#of n.
                else:
			#check for presence of opening brackets.
                        opening=re.findall("{",line)
			#check for presence of closing bracket
                        closing=re.findall("}",line)

			"""if opening bracket is found, increment the count
			increment as many brackets seen.
			avoid increament if bracket is seen in comments"""
                        if(len(opening)>0):
				#check if line is commment or not.
				comment=re.findall("\t/|\t/*",line);
				#increament only if the line is not comment.
				
				if(len(comment)==0):
					#increament n by no. of opening brackets
					n=n+len(opening);
					#print for debugging.
					#print "push", "->", opening;
					#print line;
				#end of if loop;

                      	#end of if loop 	
			
			"""if closing bracket is found, decreament the count
			decrement as many brackets seen.
			avoid decreamenting if line is commment."""
                        if(len(closing)>0):
				#check if line is comment.
				comment=re.findall("\t/|\t/*",line);
				#decreament only if line is not comment.
				if(len(comment)==0): 
					#decrease as many closing brackets seen
                                	n=n-len(closing);
					#closing of enum/struct bracket is seen
					if(n==0):
						old_string=line;
						new_string=line[0]+str(var_name[1])+"_t"+line[1:];
						key1.insert(count1,str(line));
						dict1[count1]=new_string;
						count1=count1+1; 
					#end of if loop
					#prints for debugging.
                                	#print "pop", "->", closing;
                                	#print line;
				#this is for end loop.
                                
				line1=line;
			#end of if loop.

		#end of else loop.

	#end of for loop.

#end of function initialize();

"""this will solarify the enums/structs statement. 
search for the enums/strcut, their opening and closing bracket 
pass the strings in initialize() fucntions for repalcement."""
def start():
	#global variables are now in scope
	global dict1, dict2, count1, count2, key1, key2, tempfilename1;
	#check for the length of command line arguments
	length=len(sys.argv);
	#iterate over command line arguments
	for index in range(1,length):
		filename=str(sys.argv[index]);
		#open the files
		fin=open(str(sys.argv[index]),"r");
		#bring the file pointer to beginning.
		fin.seek(0);
		#list for holding variable so that duplicates can be traced.
		str_list=list();
		#iterrate ove the lines in file
		for line in fin:
			#search for the line beginning with enum/struct based
			#on argument, it will return the variable name after 
			#accordingly followed by stuct/enum""".
			y=re.findall("^enum ([^ ]*)",line);
			#check if the line starting with enum is found.
			if(len(y)>0):
				#create the the string to be replaced
				val1="enum"+" "+y[0];
				#insert varaibles in the list for duplicates
				str_list.append(val1);   
				#print y;	
				#passed the old and new string in initialize().
				old_string="enum"+" "+str(y[0]);
				new_string="typedef"+" "+"enum"+" ";
				initialize(old_string,new_string,filename);
			#end of the if loop .

		#end of for loop for iteration over lines in fin
		
		#this will replace the declarations of enum/struct
		replace_declaration(filename);

		#open the temporary for duplicate issue.
		fin1=open(tempfilename1, "r");
		fin.seek(0);
		fin1.seek(0);
		list_length=len(str_list);
		#iterate through the list.
		for i in range(0, list_length):
			var=str_list[i];
			#iterate through the lines in file
			for line in fin1:
				#search for duplicates of var.
				y=re.findall(var, line);
				#check if duplicates are found.
				if(len(y)>0):
					#fill the dictionary and list
					key2.insert(count2, line);
					dict2[count2]=y;
					count2=count2 + 1;
					#print line;
					#print y;
				#end of if loop.
			
			#end of for loop for iterating fin1
	
		#end of for loop for iterating through the duplicate list.

 
		"""it will replace the duplicate occurances of enum/struct 
		according to new declarations"""
		replace_others();
		
		#it will delete temporary files and add changes to original.
		fini(filename);
	
	#end for for loop for iterating through the command line arguments	 	
	print("1.Solarification of enum/struct's is done");
	
#end of the function start().

start();

