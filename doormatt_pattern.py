# Enter your input from STDIN. Print output to STDOUT
num= list(map(int, input().split()))
ptrn_1="---"
ptrn_2=".|."
ptrn_3="-WELCOME-"
for i in range(0,int((num[0]-1)/2)):
    print(ptrn_1*int((num[0]-1-2*i)/2)+ptrn_2*(2*i+1)+ptrn_1*int((num[0]-1-2*i)/2))
print(ptrn_1*int((num[0]-3)/2)+ptrn_3+ptrn_1*int((num[0]-3)/2))
for i in range(0,int((num[0]-1)/2)):
    print(ptrn_1*(i+1)+ptrn_2*(2*(int((num[0]-1)/2)-i)-1)+ptrn_1*(i+1))