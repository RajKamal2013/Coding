def Search4letters(phrase:str, letters:str) -> set :
	"""Function searches for occurances of letters in phrase"""
	return set(letters).intersection(set(phrase))


letters = input("Enter the letters to search for: ");
phrase = input("Enter the phrase in which to look for: ");
found = Search4letters(phrase, letters)
print(found)
for item in found:
	print ("<--"+item+"-->")

