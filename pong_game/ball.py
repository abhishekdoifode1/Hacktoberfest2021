from turtle import Turtle

class Ball(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.color("red")
        self.penup()
        self.xmove = 10
        self.ymove = 10
        self.move_speed = 0.1

    def move_ball(self):
        self.goto(self.xcor()+self.xmove,self.ycor()+self.ymove)


    def x_bounce(self):
        self.ymove*=-1
        self.move_speed*=0.9

    def y_bounce(self):
        self.xmove*=-1
    
    def reset_game(self):
        self.goto(0,0)
        self.move_speed = 0.1
        self.y_bounce()
