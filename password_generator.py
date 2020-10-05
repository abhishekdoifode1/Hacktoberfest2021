# import modules
import tkinter
from tkinter import ttk as tk
from random import choice

# adding cut, copy, paste, select all menu to entry and text widget
class EntryPlus(tk.Entry):
	def __init__(self, *args, **kwargs):
		tk.Entry.__init__(self, *args, **kwargs)
		_rc_menu_install(self)
		self.bind("<Button-3><ButtonRelease-3>", self.rmenu)

	def rmenu(self, e):
		self.tk.call("tk_popup", self.menu, e.x_root, e.y_root)

def _rc_menu_install(w):
	w.menu = tkinter.Menu(w, tearoff=0)
	w.menu.add_command(label="Cut")
	w.menu.add_command(label="Copy")
	w.menu.add_command(label="Paste")
	w.menu.add_separator()
	w.menu.add_command(label="Select all")		

	w.menu.entryconfigure("Cut", command=lambda: w.focus_force() or w.event_generate("<<Cut>>"))
	w.menu.entryconfigure("Copy", command=lambda: w.focus_force() or w.event_generate("<<Copy>>"))
	w.menu.entryconfigure("Paste", command=lambda: w.focus_force() or w.event_generate("<<Paste>>"))
	w.menu.entryconfigure("Select all", command=lambda: w.focus_force() or w.event_generate("<Control-a>"))


class TextPlus(tkinter.Text):
	def __init__(self, *args, **kwargs):
		tkinter.Text.__init__(self, *args, **kwargs)
		_rc_menu_install(self)
		self.bind("<Button-3><ButtonRelease-3>", self.rmenu)

	def rmenu(self, e):
		self.tk.call("tk_popup", self.menu, e.x_root, e.y_root)

def _rc_menu_install(w):
	w.menu = tkinter.Menu(w, tearoff=0)
	w.menu.add_command(label="Cut")
	w.menu.add_command(label="Copy")
	w.menu.add_command(label="Paste")
	w.menu.add_separator()
	w.menu.add_command(label="Select all")		

	w.menu.entryconfigure("Cut", command=lambda: w.focus_force() or w.event_generate("<<Cut>>"))
	w.menu.entryconfigure("Copy", command=lambda: w.focus_force() or w.event_generate("<<Copy>>"))
	w.menu.entryconfigure("Paste", command=lambda: w.focus_force() or w.event_generate("<<Paste>>"))
	w.menu.entryconfigure("Select all", command=lambda: w.focus_force() or w.event_generate("<Control-a>"))

# main window
root = tkinter.Tk()
root.title('Random Password Generator')
root.resizable(0,0)

class Generator():
	# creating main widgets
	def __init__(self):
		self.frame = tk.Frame(root)
		self.len_label = tk.Label(self.frame, text='Password Length :')
		self.len_entry = EntryPlus(self.frame)
		self.gen_btn = tk.Button(self.frame, text='Generate')
		self.password_box = TextPlus(self.frame, width=10, height=10)

		self.frame.grid(row=0, column=0)
		self.len_label.grid(row=0, column=0, padx=10, pady=10, sticky='w')
		self.len_entry.grid(row=0, column=1, padx=10, pady=10, sticky='e')
		self.gen_btn.grid(row=1, column=1, padx=10, pady=10, sticky='e')
		self.password_box.grid(row=3, column=0,columnspan=2, padx=10, pady=10, sticky='ew')

		# function for generate button
		def gen_btn_command():
			# generating and storing password in a variable
			password = self.generate(int(self.len_entry.get()))
			# deleting content in password displaying box
			self.password_box.delete('1.0','end')
			# inserting generated password
			self.password_box.insert('end', password)

		self.gen_btn.config(command=gen_btn_command)

	# password generating function
	def generate(self,length):
		# character set for password. can add or remove any if wanted
		charset = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~:;,<.>/?[]{}'
		password = ''

		for n in range(length):
			x = choice(charset)
			password+=x
		return password
# calling generator class
Generator()

root.mainloop()