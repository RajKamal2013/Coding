def search4Vowels(word:str) -> set :
	""" This function find out vowels present in word !"""
	vowels = set('aeiou')
	found = vowels.intersection(set(word))
	result = found
	return (found)


def main():
	word = input ("Enter a word to search for :")
	arr = search4Vowels(word)
	print (arr)
	for elem in arr :
		print (elem + "<----->")
	


main()
