#interactive python program for converting every letter after a fullstop and every starting letter into uppercase letter
#the statement is entered by the user
sentence = input("Enter the statement:")
sen_list=list(sentence)
sen_list_final=[]
for i in range(len(sen_list)): #checking and conversion to upper case letter
  if (i==0):
    tmp=sen_list[i].upper()
    sen_list_final.append(tmp)
  elif (sen_list[i-1]=="."):
    tmp=sen_list[i].upper()
    sen_list_final.append(tmp)
  else:
    sen_list_final.append(sen_list[i])
for i in sen_list_final:
  print(i , end="")
