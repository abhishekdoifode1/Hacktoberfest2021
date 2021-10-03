#using tkinter to make a stone, paper, scissors game against computer
#import library
from tkinter import *
import random

#initialize window
root = Tk()
root.geometry('500x400')
root.resizable(0,0)
root.title('stone,Paper,Scissors')
root.config(bg ='seashell3')


#heading
Label(root, text = 'stone, Paper ,Scissors' , font='arial 20 bold', bg = 'seashell2').pack()


##user choice
user_take = StringVar()
Label(root, text = 'choose any one: stone, paper ,scissors' , font='arial 15 bold', bg = 'seashell2').place(x = 20,y=70)
Entry(root, font = 'arial 15', textvariable = user_take , bg = 'antiquewhite2').place(x=90 , y = 130)



#computer choice
comp_pick = random.randint(1,3)
if comp_pick == 1:
    comp_pick = 'stone'
elif comp_pick ==2:
    comp_pick = 'paper'
else:
    comp_pick = 'scissors'
    



##function to play
Result = StringVar()

def play():
    user_pick = user_take.get()
    if user_pick == comp_pick:
        Result.set('tie,you both select same')
    elif user_pick == 'stone' and comp_pick == 'paper':
        Result.set('you loose,computer select paper')
    elif user_pick == 'stone' and comp_pick == 'scissors':
        Result.set('you win,computer select scissors')
    elif user_pick == 'paper' and comp_pick == 'scissors':
        Result.set('you loose,computer select scissors')
    elif user_pick == 'paper' and comp_pick == 'stone':
        Result.set('you win,computer select stone')
    elif user_pick == 'scissors' and comp_pick == 'stone':
        Result.set('you loose,computer select stone')
    elif user_pick == 'scissors' and comp_pick == 'paper':
        Result.set('you win ,computer select paper')
    else:
        Result.set('invalid: choose any one -- stone, paper, scissors')
    
        
    
##fun to reset
def Reset():
    Result.set("") 
    user_take.set("")

##fun to exit
def Exit():
    root.destroy()


###### button
Entry(root, font = 'arial 10 bold', textvariable = Result, bg ='antiquewhite2',width = 50,).place(x=25, y = 250)

Button(root, font = 'arial 13 bold', text = 'PLAY'  ,padx =5,bg ='seashell4' ,command = play).place(x=150,y=190)

Button(root, font = 'arial 13 bold', text = 'RESET'  ,padx =5,bg ='seashell4' ,command = Reset).place(x=70,y=310)

Button(root, font = 'arial 13 bold', text = 'EXIT'  ,padx =5,bg ='seashell4' ,command = Exit).place(x=230,y=310)

root.mainloop()
    

