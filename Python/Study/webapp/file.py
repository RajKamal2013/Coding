with open('vsearch.log') as f:
	contents1 = f.readlines();
print (contents1)
print("<<<<--------------------->>>>")
with open('vsearch.log') as f:
	contents2 = f.read();
print(contents2)

print("<<<<--------------------->>>>")
with  open('vsearch.log') as f:
	for line in f:
		print(line)
