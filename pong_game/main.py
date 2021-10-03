from turtle import Turtle,Screen
from paddle import Paddle
from ball import Ball
from score import Score
import time


screen=Screen()
screen.setup(height=600, width=800)
screen.bgcolor("black")
screen.title("Pong Game")
screen.tracer(0)

r_paddle = Paddle((350,0))
l_paddle = Paddle((-350,0))
ball = Ball()
score = Score()

screen.listen()
screen.onkey(r_paddle.go_up,"Up")
screen.onkey(r_paddle.go_down,"Down")
screen.onkey(l_paddle.go_up,"w")
screen.onkey(l_paddle.go_down,"s")

gameIsOn = True



while gameIsOn:
    screen.update()
    ball.move_ball()
    time.sleep(ball.move_speed)
    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.x_bounce()
    
    if ball.distance(r_paddle) <50 and ball.xcor()> 320 or ball.distance(l_paddle)<50 and ball.xcor()<-320:
        ball.y_bounce()

    if ball.xcor()>380:
        ball.reset_game()
        score.l_point()

    
    if ball.xcor()<-380:
        ball.reset_game()
        score.r_point()

    if score.l_score ==10 or score.r_score == 10:
        score.gameOver()
        gameIsOn = False
        

screen.exitonclick()