# CODE: Program to illustrate one liner Quick Sort Using lambda functions

qsort = lambda x: qsort([i for i in x[1:] if i <= x[0]]  # To put all items < pivot in left array
                        ) + x[:1] + qsort(               # Pivot is 1st element
                       [i for i in x if i > x[0]]        # To put all items > pivot in right array
                        ) if x else x                # Only perform sorting if array is not None else return same array

print(qsort([3, 2, 4, 1, 8, 5, 2, 0, 5]))
print(qsort([1, 2, 5, 2, 1, 1, 4, 2, 3]))
