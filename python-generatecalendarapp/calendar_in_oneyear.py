# Program to display calendar of the given month and year

# importing calendar module
import calendar

print('####################################################')
print('####################################################')
print('########## Generate CALENDAR BY MANYMOJI ###########')
print('####################################################')
print('####################################################')
print('')
print('Please input year (Please use BE) : ')
yy = int(input())
print('')
# To take month and year input from the user
# yy = int(input("Enter year: "))
# mm = int(input("Enter month: "))

# display the calendar
for i in range(12):
    monthx = i + 1
    print(calendar.month(yy, monthx))

print('##### THANK YOU : HACKTOBERFEST 2021 #######')
