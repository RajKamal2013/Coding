import urlib
import re
from BeautifulSoup import *

url = raw_input('Enter --:')
html = urllib.urlopen(url).read()

soup = BeautifulSoup(html)

tags = soup('a')

for tag in tags:
	links=tag.get('href', none)
	print str(links)
	#print "Tag Contents" tag.contents[0]
	#print "Tag Attr" tag.attr
