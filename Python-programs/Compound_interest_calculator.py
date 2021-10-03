#interactive program to calculate compound interest
import math
def amount_CI(p , r , t , n):   #function for amount calculation  
  a =p*( math.pow( (1.0+(r/100*n)) , n*t ))
  return a

#Inputs taken and result
principal = float(input("Enter the principal:")) #type-casted to float for performing mathematical operations
rate = float(input("Enter the rate of interest:")) #type-casted to float for performing mathematical operations
time = float(input("Enter the time period for which the interest needs to be calculated:")) #type-casted to float for performing mathematical operations
number=float(input("Enter the number of times interest i compounded in a year:")) #type-casted to float for performing mathematical operations
amount = amount_CI(principal , rate , time , number) #holds the returned amount
CI = amount - principal
print( "Compound interest :",CI ) #prints the amount
print("Amount :",amount)
