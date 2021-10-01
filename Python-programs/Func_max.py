def max_array(A,n):
    #show max integer in list
    maks = 0
    for i in range(n):
        if A[i] > maks:
            maks = A[i]
    return maks