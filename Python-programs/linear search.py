arr = list() #Enter elements
e = raw_input("Enter how many elements you want: ")
print "Enter numbers in array: "

for i in range(int(e)):
    n = raw_input("e: ")
    arr.append(int(n))

x = raw_input("Element to find: ") 

def linearsearch(arr, x):
   for i in range(len(arr)):
      if arr[i] == x:
         return i
   return "Not found"

if str(linearsearch(arr,x)) == 'Not found':
    print("Element not found")    
else:
    print("Element found at index "+str(linearsearch(arr,x)))
    <!-- Mukul -->
