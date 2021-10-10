def binary_search(array, n):  
    low = 0  
    high = len(array) - 1  
    mid = 0  
  
    while low <= high:   
        mid = (high + low) // 2  
  
        if array[mid] < n:  
            low = mid + 1  
  
        elif array[mid] > n:  
            high = mid - 1  
 
        else:  
            return mid  
  
    return -1  
print("Enter the Elements of given array: ");    
array = list(map( int,input().split())) 
n=int(input("Enter the number:") ) 

    
result = binary_search(array, n)  
  
if result != -1:  
    print("Element is present at index", str(result))  
else:  
    print("Element is not present in array")  