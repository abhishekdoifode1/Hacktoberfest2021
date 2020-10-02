
#Let a,b,c are the lengths of the side of a triangle.
a=int(input("Enter a: "))
b=int(input("Enter b: "))
c=int(input("Enter c: "))
      
s=(a+b+c)/2
#Where,s is half the perimeter,
      
area=(s*(s-a)*(s-b)*(s-c))**0.5
print('The area of the triangle is %0.2f'%area)
