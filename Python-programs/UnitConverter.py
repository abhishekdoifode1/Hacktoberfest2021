def print_menu():
    print('1. Metre')
    print('2. Inch')
    print('3. Centimetre')

# cm and m
def cm_m():
    cm = float(input('Enter Lenth in Centimetre:'))
    m = cm/100
    print('Lenth in metre:{0}'.format(m))

def m_cm():
    m = float(input('Enter Lenth in Metre:'))
    cm = m*100
    print('Lenth in Centimetre:{0}'.format(cm))

# cm and in
def cm_inch():
    cm = float(input('Enter Lenth in Centimetre:'))
    inch = cm/2.5400000025908
    print('Lenth in Inch:{0}'.format(inch))

def inch_cm():
    inch = float(input('Enter Lenth in Inch:'))
    cm = inch*2.5400000025908
    print('Lenth in Centimetre:{0}'.format(cm))

# m and in
def m_inch():
    m = float(input('Enter Lenth in Metre:'))
    inch = m*39.3700787
    print('Lenth in Inch:{0}'.format(inch))

def inch_m():
    inch = float(input('Enter Lenth in Inch:'))
    m = inch/39.3700787
    print('Lenth in Metre:{0}'.format(m))



if __name__ == "__main__":
    while True:
        print('SELECT CONVERSION UNITS')
        print_menu()
        a = input('Enter First Unit:')
        b = input('Enter Second Unit:')
        if a == '1' and b == '2':
            m_inch()
        if a == '1' and b == '3':
            m_cm()
        if a == '2' and b == '1':
            inch_m()
        if a == '2' and b == '3':
            inch_cm()
        if a == '3' and b == '1':
            cm_m()
        if a == '3' and b == '2':
            cm_inch()

        answer = input('Do You Want to Exit?(y) for Yes:')
        if answer == 'y':
            break
