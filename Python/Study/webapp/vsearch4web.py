from flask import Flask, render_template, request
from mymodule1 import Search4Letters
from flask import escape

def log_request(req: 'flask_request', res: str)->None:
	with open('vsearch.log', 'a') as log:
		#print(req, res, file=log)
		#print(dir(req), res, file=log)
		print(req.form, req.remote_addr, req.user_agent, res, file=log, sep='|')
		#print(req.remote_addr, file=log)
		#print(req.user_agent, file=log)
		#print(res, file=log)
app = Flask(__name__)
@app.route('/Search4', methods=['POST'])
def do_search()->'html':
	phrase = request.form['phrase']
	letters = request.form['letters']
	title = 'Here are your results:'
	results = str(Search4Letters(phrase, letters))
	log_request(request, results)
	return render_template('results.html', 
			the_title = title,
			the_phrase = phrase,
			the_letters = letters,
			the_results = results)

@app.route('/')
@app.route('/entry')
def entry_page()->'html':
	return render_template('entry.html', 
			the_title = 'Welcome To Search4Letters on Web!')

@app.route('/viewlog')
#def view_the_log()-> str:
def view_the_log()-> 'html':
	contents=[]
	with open('vsearch.log') as log:
		#contents = log.read()
		#contents  = log.readlines()
		for line in log:
			contents.append([])
			for items in line.split('|'):
				contents[-1].append(escape(items))
	titles = ('Form Data', 'Remote Address', 'User Agents', 'Results')
	return render_template('viewlog.html',
				the_title = 'View Log',
				the_row_title=titles,
				the_data = contents
				)
	#return (escape(''.join(contents)))
	#return (str(contents))

if __name__ == '__main__':
	app.run(debug=True)
