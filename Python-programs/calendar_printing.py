import calendar   # inbuilt module

#******************************************** VARIABLES ********************************************
# year: year of the calendar
# w: Specifies the width date column
# l: Specifies the number of lines that each week will use.
# c: Number of spaces between month columns
# m: Number of months in a row


year=int(input("Enter the year:"))
width=int(input("Enter the width date column:"))
line=int(input("Enter the number of line used by per week:"))
col_space=int(input("Enter the space between month columns:"))
months=int(input("Enter the number of months in a row:"))


print(calendar.TextCalendar(firstweekday=6).formatyear(year,w=width, l=line, c=col_space, m=months))


#******************************************* Alternative *******************************************


# year=int(input("Enter the year:"))
# width=int(input("Enter how many months you want to display in a row: "))
# print(calendar.TextCalendar(firstweekday=6).formatyear(year,m=width))