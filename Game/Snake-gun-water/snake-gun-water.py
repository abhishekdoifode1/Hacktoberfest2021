def game():
    print("/////////////////// Game Developement /////////////////////")
    list = ["Snake", "Water", "Gun"]
    i = 0
    d = "\t\t\t\t\tResult : draw"
    w = "\t\t\t\t\tResult : win"
    l = "\t\t\t\t\tResult : lose"
    g = 0
    h = 0
    j = 0
    n="Winner : Human"
    m="Winner : Computer"
    r=time.asctime(time.localtime(time.time()))
    while(i<10):
     i+=1
     a=str(input("Choose from s,w Or g\n"
                "s For Snake\n"
                "w For Water\n"
                "g For Gun\n"))
     if (a=="s"):
         print("You Enter:Snake",end="                        ")
     elif(a=="w"):
        print("You Enter:Water",end="                         ")
     elif(a=="g"):
        print("You Enter:Gun",end="                           ")
     b=str(random.choice(list))
     print("Computer's Turn:",b)
     time.sleep(1)
     if(a=="w" and b=="Water"):
        print(d)
        g+=1
     elif(a=="s"and b=="Snake"):
        print(d)
        g+=1
     elif(a=="g" and b=="Gun"):
        print(d)
        g+=1
     elif (a == "s" and b == "Water"):
        print(w)
        h+=1
     elif (a == "g" and b == "Snake"):
        print(w)
        h+=1
     elif (a == "w" and b == "Gun"):
        print(w)
        h+=1
     elif (a == "s" and b == "Gun"):
        print(l)
        j+=1
     elif (a == "g" and b == "Water"):
        print(l)
        j+=1
     elif (a == "w" and b == "Snake"):
        print(l)
        j+=1
     else:
        print("\t\t\t\t\twrong Choice")
     print("(Only",10-i,"turn left)")
    time.sleep(2)
    print("            Number of Win:",h)
    print("            Number of Losses",j)
    print("            Number of Draw",g)
    if(h>j):
        print("Winner : Human")
    elif(h<j):
        print("Winner : Computer")
    else:
        print("Game Draw")

    with open("snakes.txt","a") as f:
        f.write("\n\nResults:\n")

        f.write(f"[dated:-{r}]\n\n")
        f.write("Number of Draw:")
        f.write(str(h))
        f.write("\nNumber of Win:")
        f.write(str(j))
        f.write("\nNumber of losses:")
        f.write(str(g))
        if (h > j):
            f.write("               Winner : Human       ")
        elif (h < j):
            f.write("               Winner : Computer      ")
        else:
            f.write("               Game Draw           ")
game()
print("Running Time",time.time()-initial,"seconds")
while(True):
    w=str(input("Do you Wanna Play again y for yes n for no\n"))
    if (w=="y"):
        game()
        continue
    elif(w=="n"):
        print("You Left The Game")
        break
