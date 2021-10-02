# Python program for implementation of Cocktail Sort

def cocktailSort(arr):
	n = len(arr)
	moved = True
	beg = 0
	end = n-1 
	while (moved==True):

		moved = False

		for i in range (beg, end):
			if (arr[i] > arr[i+1]) :
				arr[i], arr[i+1]= arr[i+1], arr[i]
				moved=True

		if (moved==False):
			break

		moved = False

		end = end-1

		for i in range(end-1, beg-1,-1):
			if (arr[i] > arr[i+1]):
				arr[i], arr[i+1] = arr[i+1], arr[i]
				moved = True
		beg = beg + 1

arr = [25, 32, 44, 68, 12, 19, 20]
cocktailSort(arr)
print("The sorted array is:")
for i in range(len(arr)):
	print (arr[i])
