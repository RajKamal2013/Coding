#! /usr/bin/python

class Employee:
	empcount=0;
	
	def __init__(self, a, b):
		self.name=a;
		self.salary=b;
		Employee.empcount+=1;

	def displayCount(self):
		print "Count:%d" % Employee.empcount;

	def displayEmployee(self):
		print "Employee Name=", self.name, "Employee salary=", self.salary;

emp = Employee("raj",50000);
emp2 = Employee("kamal",50000);
emp.displayEmployee();
emp2.displayEmployee();
print "Total Employee : %d" %(Employee.empcount);

