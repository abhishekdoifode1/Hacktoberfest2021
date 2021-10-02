import turtle

def Batang():
    Angle = 30

    for i in range(10):
        Titik.right(Angle)
        Titik.forward(20)
        Angle -= 5

def Balik():
    Angle = 30

    for i in range(10):
        Titik.right(Angle)
        Titik.backward(20)
        Angle -= 5

def Batang2():
    Angle = -50

    for i in range(13):
        Titik.right(Angle)
        Titik.forward(-20)
        Angle =- 5

def Batang3():
    Angle = -45

    for i in range(21):
        Titik.right(Angle)
        Titik.forward(-20)
        Angle =- 5

def Daun():
    Angle = 50

    for i in range(20):
        Titik.right(Angle)
        Titik.forward(5)
        Angle =- 5

def HalfDaun():
    Angle = 275

    for i in range(20):
        Titik.right(Angle)
        Titik.forward(5)
        Angle =- 5

def TheDaun():
    for i in range(8):
        Titik.pencolor("Green")
        Daun()
        HalfDaun()
        Titik.pencolor("Brown")


wn = turtle.Screen()

wn.title("A Little Flowers")
wn.bgcolor("Light Blue")

Titik = turtle.Turtle()
Titik.shape("blank")

Titik.speed(65)
Titik.pensize(2)

TheDaun()

Batang()
Titik.right(150)
Batang()

TheDaun()

Titik.right(-70)
Titik.penup()
Balik()
Titik.left(125)
Titik.forward(150)
Titik.right(90)
Titik.forward(180)
Titik.right(90)
Titik.pendown()

TheDaun()

Batang()
Titik.left(-55)
Batang2()

TheDaun()

Titik.left(20)
Titik.penup()
Titik.forward(550)
Titik.pendown()

TheDaun()

Batang()
Titik.left(-95)
Batang3()

TheDaun()
wn.mainloop()
