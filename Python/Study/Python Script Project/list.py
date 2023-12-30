#! /usr/bin/python
list1=[123,345,454,3232,34534];
list2=[123,345,454,3232,34534];
list3=["raj","kamal","here","I","am"];

temp=cmp(list1,list2);
print temp,"\n";
temp=cmp(list1,list3);
print temp,"\n";
list1.append(1);
print list1;
list1.insert(2,"hey");
print list1;
list1.extend(list3);
print list1;
print "reverse list"
list1.reverse();
print list1;



