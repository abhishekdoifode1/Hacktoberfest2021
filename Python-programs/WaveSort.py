def sort(arr, n): 
	
	for i in range(0, n, 2): 
		
		if (i> 0 and arr[i] < arr[i-1]): 
			arr[i],arr[i-1] = arr[i-1],arr[i] 
		
		if (i < n-1 and arr[i] < arr[i+1]): 
			arr[i],arr[i+1] = arr[i+1],arr[i] 

arr = [22,10,3,12,21,1,2002,2001] 

sort(arr, len(arr)) 
for i in range(0,len(arr)): 
	print(arr[i]) 
