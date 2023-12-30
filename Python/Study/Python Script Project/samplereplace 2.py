#! /usr/bin/python
import re

line='''enum temp { jjfj, fhjdf, jdfkd };''';
print line;

y=re.findall("^enum ([^ ]*)", line);
print y;

z="enum"+" "+str(y[0]);
print z;

x=re.findall(z,line);
print x;

new_string="typedef"+" "+"enum";
old_string=str(x[0]);
print new_string;
print old_string;

x=re.findall(old_string,line);
print "yeah", x;

line=re.sub(old_string, new_string, line);
print line;

x=re.findall("}(.*)",line);
print x;

old_string=str(x[0]);
print old_string;

new_string=" "+str(y[0])+"_t"+" "+";";
print new_string;

line=re.sub(old_string, new_string, line);
print line;
