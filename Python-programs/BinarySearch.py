# BinarySearch in python3


def BinarySearch():
    List_=list(map(int,input("Enter array list of numbers \n").split()))
    List_.sort() #sorted array list for BinarySearch
    SearchKey=int(input("Enter the Searching key \n"))
    for l in List_:
        print(l,end="  ")
    i=0
    for l in List_:
        if l==SearchKey:
            print("Found {} at {}".format(SearchKey,i+1))
            break
        i+=1

BinarySearch()
