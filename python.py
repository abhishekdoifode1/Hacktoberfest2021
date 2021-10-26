   Python Function
  Functions are the most important aspect of an application. A function can be defined as the organized block of reusable code, which can be called whenever required.

Python allows us to divide a large program into the basic building blocks known as a function. The function contains the set of programming statements enclosed by {}. A function can be called multiple times to provide reusability and modularity to the Python program.

The Function helps to programmer to break the program into the smaller part. It organizes the code very effectively and avoids the repetition of the code. As the program grows, function makes the program more organized.

Python provide us various inbuilt functions like range() or print(). Although, the user can create its functions, which can be called user-defined functions.
There are mainly two types of functions.

User-define functions - The user-defined functions are those define by the user to perform the specific task.
Built-in functions - The built-in functions are those functions that are pre-defined in Python.
In this tutorial, we will discuss the user define functions.

Advantage of Functions in Python
There are the following advantages of Python functions.

Using functions, we can avoid rewriting the same logic/code again and again in a program.
We can call Python functions multiple times in a program and anywhere in a program.
We can track a large Python program easily when it is divided into multiple functions.
Reusability is the main achievement of Python functions.
However, Function calling is always overhead in a Python program.
Creating a Function
Python provides the def keyword to define the function. The syntax of the define function is given below.

Syntax:

def my_function(parameters):  
      function_block  
return expression  
Let's understand the syntax of functions definition.

The def keyword, along with the function name is used to define the function.
The identifier rule must follow the function name.
A function accepts the parameter (argument), and they can be optional.
The function block is started with the colon (:), and block statements must be at the same indentation.
The return statement is used to return the value. A function can have only one return
Function Calling
In Python, after the function is created, we can call it from another function. A function must be defined before the function call; otherwise, the Python interpreter gives an error. To call the function, use the function name followed by the parentheses.
Example 1
# Defining function  
def sum():  
    a = 10  
    b = 20  
    c = a+b  
    return c  
# calling sum() function in print statement  
print("The sum is:",sum())  
Output:

The sum is: 30
In the above code, we have defined the function named sum, and it has a statement c = a+b, which computes the given values, and the result is returned by the return statement to the caller function.
Example 2 Creating function without return statement
# Defining function  
def sum():  
    a = 10  
    b = 20  
    c = a+b  
# calling sum() function in print statement  
print(sum())  
Output:


None
In the above code, we have defined the same function without the return statement as we can see that the sum() function returned the None object to the caller function.

Arguments in function
The arguments are types of information which can be passed into the function. The arguments are specified in the parentheses. We can pass any number of arguments, but they must be separate them with a comma.

Consider the following example, which contains a function that accepts a string as the argument.

Example 1
#defining the function    
def func (name):    
    print("Hi ",name)   
#calling the function     
func("Devansh")     
Output:

Hi Devansh
Example 2
#Python function to calculate the sum of two variables     
#defining the function    
def sum (a,b):    
    return a+b;    
    
#taking values from the user    
a = int(input("Enter a: "))    
b = int(input("Enter b: "))    
    
#printing the sum of a and b    
print("Sum = ",sum(a,b))    
Output:

Enter a: 10
Enter b: 20
Sum =  30
Call by reference in Python
In Python, call by reference means passing the actual value as an argument in the function. All the functions are called by reference, i.e., all the changes made to the reference inside the function revert back to the original value referred by the reference.

Example 1 Passing Immutable Object (List)
#defining the function    
def change_list(list1):    
    list1.append(20)   
    list1.append(30)    
    print("list inside function = ",list1)    
    
#defining the list    
list1 = [10,30,40,50]    
    
#calling the function     
change_list(list1)  
print("list outside function = ",list1)  
Output:

list inside function =  [10, 30, 40, 50, 20, 30]
list outside function =  [10, 30, 40, 50, 20, 30]
Example 2 Passing Mutable Object (String)
#defining the function    
def change_string (str):    
    str = str + " Hows you "  
    print("printing the string inside function :",str)  
    
string1 = "Hi I am there"    
    
#calling the function    
change_string(string1)    
    
print("printing the string outside function :",string1)    
Output:

printing the string inside function : Hi I am there Hows you 
printing the string outside function : Hi I am there
Consider the following example of a simple example that prints the message "Hello World".


#function definition  
def hello_world():    
    print("hello world")    
# function calling  
hello_world()      
Output:

hello world
Example 1
# Defining function  
def sum():  
    a = 10  
    b = 20  
    c = a+b  
    return c  
# calling sum() function in print statement  
print("The sum is:",sum())  
Output:

The sum is: 30
In the above code, we have defined the function named sum, and it has a statement c = a+b, which computes the given values, and the result is returned by the return statement to the caller function.
Example 2 Creating function without return statement
# Defining function  
def sum():  
    a = 10  
    b = 20  
    c = a+b  
# calling sum() function in print statement  
print(sum())  
Output:


None
In the above code, we have defined the same function without the return statement as we can see that the sum() function returned the None object to the caller function.

Arguments in function
The arguments are types of information which can be passed into the function. The arguments are specified in the parentheses. We can pass any number of arguments, but they must be separate them with a comma.

Consider the following example, which contains a function that accepts a string as the argument.

Example 1
#defining the function    
def func (name):    
    print("Hi ",name)   
#calling the function     
func("Devansh")     
Output:

Hi Devansh
Example 2
#Python function to calculate the sum of two variables     
#defining the function    
def sum (a,b):    
    return a+b;    
    
#taking values from the user    
a = int(input("Enter a: "))    
b = int(input("Enter b: "))    
    
#printing the sum of a and b    
print("Sum = ",sum(a,b))    
Output:

Enter a: 10
Enter b: 20
Sum =  30
Call by reference in Python
In Python, call by reference means passing the actual value as an argument in the function. All the functions are called by reference, i.e., all the changes made to the reference inside the function revert back to the original value referred by the reference.

Example 1 Passing Immutable Object (List)
#defining the function    
def change_list(list1):    
    list1.append(20)   
    list1.append(30)    
    print("list inside function = ",list1)    
    
#defining the list    
list1 = [10,30,40,50]    
    
#calling the function     
change_list(list1)  
print("list outside function = ",list1)  
Output:

list inside function =  [10, 30, 40, 50, 20, 30]
list outside function =  [10, 30, 40, 50, 20, 30]
Example 2 Passing Mutable Object (String)
#defining the function    
def change_string (str):    
    str = str + " Hows you "  
    print("printing the string inside function :",str)  
    
string1 = "Hi I am there"    
    
#calling the function    
change_string(string1)    
    
print("printing the string outside function :",string1)    
Output:

printing the string inside function : Hi I am there Hows you 
printing the string outside function : Hi I am there
