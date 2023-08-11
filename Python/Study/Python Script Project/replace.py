#! /usr/bin/python
import re,sys,os

#this is associcate array , a dictionary to maintain old_string and new_string
#latter old_string is replaced with new_string
dict={};
dict2={}
key=list();
count=0;
key2=list();
count2=0;
tempfilename1="abc123.h";
tempfilename2="abcxyz.h";

def fun5(filename):
	os.remove(filename);
	os.remove(tempfilename1);
	os.rename(tempfilename2,filename);
	


def fun4():
	global tempfilename1;
	global tempfilename2;
	global dict2;
	global key2;
	global count2;
	fin1=open(tempfilename1,"r");
	fin2=open(tempfilename2,"w+");
	for line in fin1:
		for src,target in dict2.iteritems():
		# 	print key2[src];   
		#	print target;
			y=re.findall("enum ([^ ]*)", str(target[0]));
			z=re.findall(str(target[0]), line);
			if(len(z)>0):
			#	print y;
			#	print line;
				old_string=str(target[0]);
				new_string=str(y[0])+"_t";
			#	print old_string;
			#	print new_string;
				line=line.replace(old_string, new_string);
			#	print line;
		fin2.write(line);
	fin1.close();
	fin2.close();	

def fun3(filename):
	global tempfilename1
	global key;
	global dict;
	fin1=open(filename, "r");
	fin2=open(tempfilename1,"w+");
	for line in fin1:
		for src, target in dict.iteritems():
			line=line.replace(key[src], target);
		
		fin2.write(line);
	fin1.close();
	fin2.close();
		

#this will do the repalcement as follows.
# enum temp {...}; to typedef enum {...} temp_t};
def fun2(old_string, new_string, filename):
#       print filename;
#	open the file and bring the file pointer to beginning.
        fin1=open(filename,"r+");
        fin1.seek(0);
        pos=0;
#	set n=-1 so that we can set to 1 first time old_string appears
        n=-1;
#	making the global dictionary variable accesible in this scope
	global dict;
#	making the gloabl list variable accessible in this scope
	global key;
#	making global count variable accessible in this scope
	global count;
#	list contaning the enum name.
	enum_name=list();
#	iterate through the file line by line. 
        for line in fin1:
	#	till the first occurance of old_String is detected.
                if(n==-1):
		#	searcing for old_string in line
                        y=re.findall("^"+old_string, line);
		#	if old string is found, the length will be positive
		#	set the n=1 indocating first occurance is found.
                        if(len(y)>0):
			#	print the start line ,just for debugging
                        #       print "start->", line
                                n=1;
				enum_name=old_string.split(" ");
			#	print enum_name;
			#	print "old string-> ",line;
			#	print "new_String->", new_string+"{";
				key.insert(count,line);
				dict[count]=new_string+ "{"+"\n";
				count=count+1;
			#end of if loop for checking the starting occurance.
 
	#	indicate the end of the enum that is the closing bracket is seen.
                elif(n==0):
		#	print the final line for debugging.
                #	print "End->",line1+line
                        break;
		#	end of elif loop.
		
	
	#	check for opening and closing bracket in the line and
	#	increment and decreament the count based on brackets.
                else:
		#	check for presence of opening brackets.
                        opening=re.findall("{",line)
		#	check for presence of closing bracket
                        closing=re.findall("}",line)

		#	if opening bracket is found, increment the count
		#	increment as many brackets seen.
		#	avoid increament if bracket is seen in comments
                        if(len(opening)>0):
			#	search if line is commment or not.
				comment=re.findall("\t/|\t/*",line);

			#	increament only if the line is not comment.
			#	in that case lenght will be zero.
				if(len(comment)==0):
				#	increament n by no. of opening brackets
					n=n+len(opening);
				#	print for debugging.
				#	print "push", "->", opening;
				#	print line;
				#end of if loop;
                      	#end of if loop 	
			
		#	if closing bracket is found, decreament the count
		#	decrement as many brackets seen.
		#	avoid decreamenting if line is commment.
                        if(len(closing)>0):
			#	check if line is comment, stats with \t* or \t/*
				comment=re.findall("\t/|\t/*",line);
				
			#	decreament only if line is not comment.
			#	in that case lenght will be zero.
				if(len(comment)==0):                                                        
				#	decrease as many closing brackets seen
                                	n=n-len(closing);
					if(n==0):
						old_string=line;
						#print "old_string-> ", line;
						new_string=line[0]+str(enum_name[1])+"_t"+line[1:];
						#print "new_string-> ", new_string;
						key.insert(count,str(line));
						dict[count]=new_string;
						count=count+1;
				#	prints for debugging.
                                #	print "pop", "->", closing;
                                #	print line;
				#	this is for end loop.
                                	line1=line;
				#end of if loop.
			#end of if loop for closing bracket.
		#end of else loop.
	#end of for loop.
#end of function.

#this will solarify the enums. 
#search for the enums , their opening and closing bracket 
#pass the strings in fun2() for repalcement.
def fun1():
	global dict;
	global key;
	global count;
	global dict2;
	global key2;
	global count2;
	global tempfilename1;
#	check for the length of command line arguments
	length=len(sys.argv);
#	iterate over command line arguments
	for index in range(1,length):
		filename=str(sys.argv[index]);
	#	print "filename->",filename;
		filename_name="new"+str(sys.argv[index]);
	#	print "New filename->:", filename_name;
	#	open the files
		fin=open(str(sys.argv[index]),"a+");
	#	bring the file pointer to beginning.
		fin.seek(0);
	#	list for holding variable so that duplicates can be traced.
		str_list=list();
	#	iterrate ove the lines in file
		for line in fin:
		#	search for the line beginnin with enum.
		#	it will return the variable name after enum
			y=re.findall("^enum ([^ ]*)",line);
		#	check if the line starting with enum is found.
			if(len(y)>0):
			#	create the the string to be replaced
				val1="enum"+" "+y[0];
			#	appending varaibles in the list so that duplicates
			#	can be found.
				str_list.append(val1);   
			#	Implement -> replace the line with typedef enum {---------------------> to be done.
			#	print y;	
			#	passed the old and new string to get repalced in the function.
				old_string="enum"+" "+str(y[0]);
				new_string="typedef"+" "+"enum"+" ";
				fun2(old_string,new_string,filename);
			#	end of the if loop . 

	#	end of the iterating through the file. (for loop)
		
	#	this is for find the repeatition of the string in the list.
	#	seek the file to beginning.
	fun3(filename);
	fin1=open(tempfilename1,"r");
	fin1.seek(0);
        fin.seek(0);
	list_length=len(str_list);
#	iterate through the list.
	for i in range(0,list_length):
		extra_var=str_list[i];
	#	iterate through the lines in the file
		for line in fin1:
		#	search for the repeated variable.
			y=re.findall(extra_var,line);
			if(len(y)>0):
				key2.insert(count2, line);
				dict2[count2]=y;
				count2=count2+1;
				#print y;
				#print line;	
		#end of the for loop for iterating over the file.
	#end of the for loop for iterating over the list.
	
	#fun4() will replace all the repeated occurances of enum in file
	fun4();
	#fun5() will delete temporary files and add changes to the original file
	fun5(filename);
	print "1.Repalcing enum is done";
#	end of the function fun1() and all searching and replacing is done.

			
fun1();
