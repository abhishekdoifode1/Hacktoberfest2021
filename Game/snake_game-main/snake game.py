import pygame as py
import random as rd
py.init()
py.mixer.init()
py.mixer.music.load("snakegametone.mp3")
py.mixer.music.set_volume(0.7)
#colors
red=(255,0,0)
green=(0,255,0)
blue=(0,0,255)
white=(255,255,255)
black=(0,0,0)
purple=(66, 135, 245)
#creating window
gamewindow=py.display.set_mode((900,500))
py.display.set_caption("snake game")
bgimg=py.image.load('background2.jpg')
bgimg=py.transform.scale(bgimg,(900,500)).convert_alpha()
py.display.update()
#function

def plot_snake(gamewindow,color,snk_length,s_size_x,s_size_y):
    for x,y in snk_length[:-1]:
        py.draw.rect(gamewindow,purple,[x,y,s_size_x,s_size_y])
    py.draw.rect(gamewindow,blue,[snk_length[-1][0],snk_length[-1][1],s_size_x,s_size_y])
font=py.font.SysFont(None,50)
def text_screen(text,color,x,y):
    screen_text=font.render(text,True,color)
    gamewindow.blit(screen_text,[x,y])

#clock
clock=py.time.Clock()
#game loop
def gameloop():
    bgimg=py.image.load('background2.jpg')
    bgimg=py.transform.scale(bgimg,(900,500)).convert_alpha()
    with open("highscore.txt","r") as f:
        hiscore=f.read()
    quit_game=False
    game_over=False
    s_x=450
    s_y=250
    s_size_x=10
    s_size_y=10
    fps=10
    vel_x=0
    vel_y=0
    food_x=rd.randint(10,880)
    food_y=rd.randint(150,480)
    score=0
    size=1
    snk_length=[]
    level=1
    py.mixer.music.play()
    n=0
    while not quit_game:
        if n==150:
                py.mixer.music.play()
                n=0
        n+=1
        if game_over:
            py.mixer.music.pause()
            gamewindow.fill(white)
            with open("highscore.txt","w") as f:
                f.write(str(hiscore))
            text_screen("Game Over\n    press enter to continue",red,150,250)
            for event in py.event.get():
                if event.type==py.QUIT:
                    quit_game=True
                if event.type==py.KEYDOWN:
                    if event.key==py.K_ESCAPE:
                        quit_game=True
                    if event.key==py.K_RETURN:
                        game_over=False
                        gameloop()
        
        else:
            for event in py.event.get():
                if event.type==py.QUIT:
                    quit_game=True
                if event.type==py.KEYDOWN:
                    if event.key==py.K_RIGHT:
                        if vel_x != -10:
                            vel_x=10
                            vel_y=0
                        
                    elif event.key==py.K_DOWN:
                        if vel_y != -10:
                            vel_y=10
                            vel_x=0
                        
                    elif event.key==py.K_LEFT:
                        if vel_x != 10:
                            vel_x=-10
                            vel_y=0
                        
                    elif event.key==py.K_UP:
                        if vel_y != 10:
                            vel_y=-10
                            vel_x=0
                    
                        
                    elif event.key==py.K_ESCAPE:
                        quit_game=True
            s_x+=vel_x
            s_y+=vel_y
            if score>1000:
                fps=20
            if abs(s_x-food_x)<10 and abs(s_y-food_y)<10:
                score+=100
                food_x=rd.randint(10,890)
                food_y=rd.randint(10,490)
                size+=1
            head=[]
            head.append(s_x)
            head.append(s_y)
            snk_length.append(head)
            if len(snk_length)>size:
                del(snk_length[0])
            if s_x>880 or s_x<10 or s_y>480 or s_y<10:
                game_over=True
            if head in snk_length[0:-1]:
                game_over=True
            if (score)>int(hiscore):
                hiscore=score
            
            gamewindow.fill(white)
            gamewindow.blit(bgimg,(0,0))
            text_screen(f"Score:{str(score)}",red,10,10)
            text_screen(f"High Score:{str(hiscore)}",red,500,10)
            plot_snake(gamewindow,black,snk_length,s_size_x,s_size_y)
            if score>200:
                py.draw.rect(gamewindow,green,[400,300,100,20])
                if 400<=s_x<=500 and 300<=s_y<=320:
                    game_over=True
                level=2
            if score>500:
                py.draw.rect(gamewindow,green,[300,300,200,20])
                if 300<=s_x<=500 and 300<=s_y<=320:
                    game_over=True
                level=3
            text_screen(f"Level:{str(level)}",red,200,10)
            py.draw.rect(gamewindow,green,[0,0,900,10])
            py.draw.rect(gamewindow,green,[0,490,900,10])
            py.draw.rect(gamewindow,green,[0,0,10,500])
            py.draw.rect(gamewindow,green,[890,0,10,500])
            py.draw.rect(gamewindow,black,[food_x,food_y,10,10])
            clock.tick(fps)
            
            # py.draw.circle(gamewindow,red,[100,100],20)
        py.display.update()
    
    
gameloop()
py.quit()
quit()
