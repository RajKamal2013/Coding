#! /usr/bin/python

tuple1=(1,2,3,4,5);
tuple2=(1,2,3,4,5);
tuple3=("hi", "I","am","here");

temp=cmp(tuple1,tuple2);
print temp;
temp=cmp(tuple1,tuple3);
print temp;

n=len(tuple1);
print n;

tuple4=tuple1+tuple2;
print tuple4;

print tuple1;
print tuple2;
print tuple3;
