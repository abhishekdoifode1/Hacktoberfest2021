a = input("Input password:")
b = "Doni"
for i in range(2):
    if a==b:
        print ("your login is success")
        break
    else:
        c = input("Sorry, your password is not correct. Input password:")
        if c==b:
            print ("Anda berhasil login")
            break
        elif i==1:
            print ("you had tried 3 times. your access is dennied.")
