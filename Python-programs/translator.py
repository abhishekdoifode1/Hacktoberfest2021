import random

def translate(phrase):
	translation = ""
	for letter in phrase:
		if letter.lower() in "aeiou":
			if letter.isupper():
				translation = translation + random.choice(["Ä", "Ö", "Ü"])
			else:
				translation = translation + random.choice(["ä", "ö", "ü"])
		else:
			translation = translation + letter
	return translation

print(translate(input("Enter a phrase: ")))