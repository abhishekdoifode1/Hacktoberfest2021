from turtle import Turtle

class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.color("white")
        self.penup()
        self.hideturtle()
        self.l_score = 0
        self.r_score = 0
        self.update_score()




    def update_score(self):
        self.clear()
        self.goto(-100,200)
        self.write(self.l_score,align="center",font=("Courier",80,"normal"))
        self.goto(100,200)
        self.write(self.r_score,align="center",font=("Courier",80,"normal"))



    def l_point(self):
        self.l_score+=1
        self.update_score()

    def r_point(self):
        self.r_score+=1
        self.update_score()

    def gameOver(self):
        self.goto(0,0)
        self.color("red")
        if(self.l_score == 10):
            self.write(f"Left Won!", align="center", font=("Courier",30,'normal'))
        else:
            self.write(f"Right Won!", align="center", font=("Courier",30,'normal'))
