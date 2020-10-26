def increasing_comparator(a, b):
    return a < b

def decreasing_comparator(a, b):
    return a >= b

def swap(arr, index1, index2):
    arr[index1], arr[index2] = arr[index2], arr[index1]

def bubble_sort(arr, comparator=increasing_comparator):
    go = True

    while go:
        go = False
        for i in range(len(arr)-1):
            if comparator(arr[i+1], arr[i]):
                swap(arr, i, i+1)
                go = True