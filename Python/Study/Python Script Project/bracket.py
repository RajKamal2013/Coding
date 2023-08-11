#! /usr/bin/python
import re,sys

count_enum=0;
count_bracket=0;
#assuming bracket "{" is on the same line as enum. 
def fun2(string,filename):
#	print filename;
	fin1=open(filename,"r");
	fin1.seek(0);
	pos=0;
	n=-1;
	line1="";
	global count_bracket;
	#print "bracket testing";
	for line in fin1:
		if(n==-1):
			y=re.findall("^"+string, line);
			if(len(y)>0):
				print "start->", line
				print "push"
				#print line;
				n=1;
				count_bracket=count_bracket+1;
		elif(n==0):
			print "End->",line1+line
			break;
		else:
			opening=re.findall("{",line)
			closing=re.findall("}",line)
		
			if(len(opening)>0):
				comment=re.findall("\t/|\t/*",line);
				#if(len(comment)>0):
					#print comment;
					#print line;
				if(len(comment)==0):
					n=n+len(opening);
					count_bracket=count_bracket+len(opening);
					print "opening->", line;
					print line;
					print "push";
			if(len(closing)>0):
				#n=n-len(closing);
				comment=re.findall("\t/|\t/*",line);
				#if(len(comment)>0):
					#print comment;
					#print line;
			        if(len(comment)==0):	
					n=n-len(closing);
					print "closing->", line;	
					print "pop";
					line1=line;
	
	#print "bracket done";
			



def fun1():
        length=len(sys.argv);
        for index in range(1,length):
                filename_name="new"+str(sys.argv[index]);
		filename=str(sys.argv[index]);
               # print "filename :", filename;
                fin=open(str(sys.argv[index]),"r");
                fout=open(filename_name,"w");
                fin.seek(0);
                fout.seek(0);
                str_list=list();
		global count_enum;
                for line in fin:
                        y=re.findall("^enum ([^ ]*)",line);
			count_enum=count_enum+len(y);
                #       z=re.findall("^};",line);
                        if(len(y)>0):
                                val1="enum"+" "+y[0];
                                str_list.append(val1);
                                #replace the line with typedef enum {
                               # print y;
                                old_string="enum"+" "+str(y[0]);
				#print old_string;
                                new_string="typedef"+" "+"enum"+" ";
				fun2(old_string,filename);
                                #re.sub(old_string,new_string,line);
                        #if(len(z)>0):
                       #         print line;
                        fout.write(line);
                #fin.seek(0);
                #list_length=len(str_list);
                #for i in range(0,list_length):
                 #       extra_var=str_list[i];
                  #      for line in fin:
                   #             y=re.findall(extra_var,line);
                    #            if(len(y)>0):
                     #                   print y;


        print "done";

fun1();
print "count of enum",count_enum;
print "count of bracket", count_bracket;
