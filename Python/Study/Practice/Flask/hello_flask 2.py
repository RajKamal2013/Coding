from flask import Flask
from mymodule1 import Search4Letters
from mymodule1 import Search4Vowels
from mymodule1 import Speak4Time

#found = Search4Letters('I am on my way to Python web', 'aeiou')
#print (found)
app = Flask(__name__)
app.debug=True
@app.route('/')
#def hello() -> str:
#	print (__name__)
#	return "Hello World from Flask !"

#@app.route('/Search')
def do_search() -> str:
	print (__name__)
	#found = Search4Letters('I am on my way to Python web', 'aeiou')
	#print (found)
	vowels = Search4Vowels('I am on my way to Python web')
	str1 = ', '.join(str(e) for e in vowels)
	return (str1)

#dump()
app.run()
