from tkinter import *
from tkinter.font import BOLD
from tkinter.ttk import *

from time import strftime

root=Tk()
root.title('clock')

def time():
    string=strftime('%H:%M:%S')
    label.config(text=string)
    label.after(1000,time)
label= Label(root, font=('Comic sans ms',80, BOLD), background="Black",foreground='lime')
label.pack(anchor='center')

time()

mainloop()
