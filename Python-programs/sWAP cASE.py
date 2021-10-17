#This program swaps case of given input text
text = input("Enter Text : ")
res=""
for i in text:
  if i.isupper():
    res = res + i.lower()
  elif i.islower():
    res = res + i.upper()
  else:
    res = res + i
print("Text with swapped case : ",res)  
