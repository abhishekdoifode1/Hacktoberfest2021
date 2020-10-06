import pygame
import random
import configparser
pygame.init()

screen = pygame.display.set_mode((500, 700))

pygame.display.set_caption("The Death River")


game_died = False
game_success = False
game_result = False
game_firstbg = True
bgfirst = pygame.image.load('river-of-death.jpg')
bgfirst = pygame.transform.scale(bgfirst, (500, 700))
bg = pygame.image.load('map.png')
bg = pygame.transform.scale(bg, (500, 700))
char = pygame.image.load('attack1_33.png')
char2 = pygame.image.load('attack1_44.png')
charship = pygame.image.load('moving1.png')
charship2 = pygame.image.load('moving2.png')
charship3 = pygame.image.load('moving3.png')
charship4 = pygame.image.load('moving4.png')
character = pygame.image.load('char1.png')
character = pygame.transform.scale(character, (30, 20))
character1 = pygame.image.load('char2.png')
character1 = pygame.transform.scale(character1, (30, 20))
vellow = [1.5, 1.75, 2, 2.5, 3, 4, 4.25, 4.75, 5.25, 6, 7.5, 8.5]
velhigh = [2.5, 2.75, 3.5, 3.75, 4.5, 5.25, 5.75, 6.5, 7.5, 8, 10]
hitboxx = []
hitboxy = []
hitboxwx = []
hitboxwy = []
# time = pygame.time.time()
x = 25
y = 70
harshit = configparser.RawConfigParser()
harshit.read('./configure.cfg')
xship = harshit.getfloat("info", "xship")
yship = harshit.getfloat("info", "yship")
xship2 = harshit.getfloat("info", "xship2")
yship2 = harshit.getfloat("info", "yship2")
xship3 = harshit.getfloat("info", "xship3")
yship3 = harshit.getfloat("info", "yship3")
xship4 = harshit.getfloat("info", "xship4")
yship4 = harshit.getfloat("info", "yship4")
xship5 = harshit.getfloat("info", "xship5")
yship5 = harshit.getfloat("info", "yship5")
xship6 = harshit.getfloat("info", "xship6")
yship6 = harshit.getfloat("info", "yship6")
xchar1 = harshit.getint("info", "xchar1")
ychar1 = harshit.getint("info", "ychar1")
xchar2 = harshit.getint("info", "xchar2")
ychar2 = harshit.getint("info", "ychar2")
k = harshit.getint("info", "k")


class boot1:
    def __init__(self, xchar1, ychar1, level, score1, timebonus):
        self.xchar1 = xchar1
        self.ychar1 = ychar1
        self.level = level
        self.score = score1
        self.timebonus = timebonus


class boot2:
    def __init__(self, xchar2, ychar2, level, score2, timebonus):
        self.xchar2 = xchar2
        self.ychar2 = ychar2
        self.level = level
        self.score = score2
        self.timebonus = timebonus


def redrawGameWindow():
    # global x, y
    if game_firstbg:
        screen.blit(bgfirst, (0, 0))

    if not game_died and not game_success and not game_result and not game_firstbg:
        screen.blit(bg, (0, 0))
        # print(k)
    # screen.blit(char, (x, y))
    # screen.blit(char, (x, y + 110))
        font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 20)
        score_type = "SCORE : "
        if k == 0:
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 20)
            score_type = "SCORE : "
            score_text = font.render(score_type + " " + str(p1.score), 1, (255, 255, 255))
            screen.blit(score_text, (0, 0))
            level_type = "LEVEL : "
            level_text = font.render(level_type + str(p1.level), 1, (255, 255, 255))
            screen.blit(level_text, (380, 0))
        else:
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 20)
            score_type = "SCORE : "
            score_text = font.render(score_type + " " + str(p2.score), 1, (255, 255, 255))
            screen.blit(score_text, (0, 0))
            level_type = "LEVEL : "
            level_text = font.render(level_type + str(p2.level), 1, (255, 255, 255))
            screen.blit(level_text, (380, 0))

        x = 25
        y = 70
        i = 0
        while i < 3:
            j = 0
            while j < 8 and i % 2 == 0:
                screen.blit(char, (x, y))
                hit = (x + 32, y + 30, 20, 27)
                hitboxx.append(x + 32)
                hitboxy.append(y + 30)
                hitboxwx.append(20)
                hitboxwy.append(27)
            # pygame.draw.rect(screen, (255,0,0), hit, 2)
                x = x + 120
                j = j + 2

            x = 25
            y = y + 110
            i = i + 1

        x = 85
        y = 180
        j = 0
        while j < 4:
            screen.blit(char, (x, y))
            hit = (x + 32, y + 30, 20, 27)
            hitboxx.append(x + 32)
            hitboxy.append(y + 30)
            hitboxwx.append(20)
            hitboxwy.append(27)
        #  pygame.draw.rect(screen, (255,0,0), hit, 2)
            x = x + 120
            j = j + 1

        x = 85
        y = 410
        j = 0
        while j < 4:
            screen.blit(char, (x, y))
            hit = (x + 32, y + 30, 20, 27)
            hitboxx.append(x + 32)
            hitboxy.append(y + 30)
            hitboxwx.append(20)
            hitboxwy.append(27)
            # pygame.draw.rect(screen, (255,0,0), hit, 2)
            x = x + 120
            j = j + 1

        x = 25
        y = 520
        j = 0
        while j < 4:
            screen.blit(char, (x, y))
            hit = (x + 32, y + 30, 20, 27)
            hitboxx.append(x + 32)
            hitboxy.append(y + 30)
            hitboxwx.append(20)
            hitboxwy.append(27)
            # pygame.draw.rect(screen, (255,0,0), hit, 2)
            x = x + 120
            j = j + 1

        screen.blit(charship, (xship, yship))
        hitbox1 = (xship, yship, 100, 55)
        # pygame.draw.rect(screen, (255,0,0), hitbox1, 2)

        screen.blit(charship2, (xship2, yship2))
        hitbox2 = (xship2, yship2, 130, 40)
        # pygame.draw.rect(screen, (255,0,0), hitbox2, 2)

        screen.blit(charship, (xship3, yship3))
        hitbox3 = (xship3, yship3, 100, 55)
        # pygame.draw.rect(screen, (255,0,0), hitbox3, 2)

        screen.blit(charship3, (xship4, yship4))
        hitbox4 = (xship4 + 10, yship4, 85, 70)
        # pygame.draw.rect(screen, (255,0,0), hitbox4, 2)

        screen.blit(charship4, (xship5, yship5))
        hitbox5 = (xship5 + 10, yship5, 70, 60)
        # pygame.draw.rect(screen, (255,0,0), hitbox5, 2)

        screen.blit(charship2, (xship6, yship6))
        hitbox6 = (xship6, yship6, 130, 40)
        # pygame.draw.rect(screen, (255,0,0), hitbox6, 2)
        if k == 0:
            screen.blit(character, (p1.xchar1, p1.ychar1))
            hitboxchar = (p1.xchar1, p1.ychar1, 25, 20)
        else:
            screen.blit(character1, (p2.xchar2, p2.ychar2))
            hitboxchar = (p2.xchar2, p2.ychar2, 25, 20)
        # pygame.draw.rect(screen , (255,0,0), hitboxchar, 2)

    elif not game_result and not game_firstbg:
        if game_died or game_success:
            screen.fill((255, 255, 255))
            if k == 0:
                if game_died:
                    font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
                    final_type = font.render("Ended", 1, (255, 0, 0))
                    screen.blit(final_type, (170, 300))
                    final_score = font.render("P1 Score : " + str(p1.score), 1, (0, 0, 0))
                    screen.blit(final_score, (170, 370))
                    final_bonus = font.render(
                        "Time Bonus : " + "+" + str(p1.timebonus),
                        1,
                        (0, 0, 255)
                    )
                    screen.blit(final_bonus, (170, 440))
                    change_char = font.render("Press Enter to Continue ", 1, (100, 100, 100))
                    screen.blit(change_char, (70, 510))

                elif game_success:
                    font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
                    final_type = font.render("Success", 1, (0, 255, 0))
                    screen.blit(final_type, (170, 300))
                    final_score = font.render("P1 Score : " + str(p1.score), 1, (0, 0, 0))
                    screen.blit(final_score, (170, 370))
                    final_bonus = font.render(
                        "Time Bonus : " + "+" + str(p1.timebonus),
                        1,
                        (0, 0, 255)
                        )
                    screen.blit(final_bonus, (170, 440))
                    change_char = font.render("Press Enter to Continue ", 1, (100, 100, 100))
                    screen.blit(change_char, (70, 510))

            else:
                # game_result = True
                if game_died:
                    font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
                    final_type = font.render("Ended", 1, (255, 0, 0))
                    screen.blit(final_type, (170, 300))
                    final_score = font.render("P2 Score : " + str(p2.score), 1, (0, 0, 0))
                    screen.blit(final_score, (170, 370))
                    final_bonus = font.render(
                        "Time Bonus : " + "+" + str(p2.timebonus),
                        1,
                        (0, 0, 255)
                        )
                    screen.blit(final_bonus, (170, 440))
                    change_char = font.render("Press Enter to Continue ", 1, (100, 100, 100))
                    screen.blit(change_char, (70, 510))

                elif game_success:
                    font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
                    final_type = font.render("Success", 1, (0, 255, 0))
                    screen.blit(final_type, (170, 300))
                    final_score = font.render("P2 Score : " + str(p2.score), 1, (0, 0, 0))
                    screen.blit(final_score, (170, 370))
                    final_bonus = font.render(
                        "Time Bonus : " + "+" + str(p2.timebonus),
                        1,
                        (0, 0, 255)
                        )
                    screen.blit(final_bonus, (170, 440))
                    change_char = font.render("Press Enter to Continue ", 1, (100, 100, 100))
                    screen.blit(change_char, (70, 510))

    elif game_result and k == 1 and not game_firstbg:
        # print("hiii")
        screen.fill((255, 255, 255))
        if p1.score > p2.score:
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
            judge_text = font.render(" P1 Wins ", 1, (255, 0, 0))
            screen.blit(judge_text, (140, 320))
            score_text = font.render("P1: " + str(p1.score), 1, (255, 0, 0))
            score1_text = font.render("P2: " + str(p2.score), 1, (255, 0, 0))
            screen.blit(score_text, (140, 360))
            screen.blit(score1_text, (140, 400))
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 20)
            continue_text = font.render(" Press C To Continue ", 1, (100, 100, 100))
            screen.blit(continue_text, (70, 470))

        elif p2.score > p1.score:
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
            judge_text = font.render(" P2 Wins ", 1, (255, 0, 0))
            screen.blit(judge_text, (140, 320))
            score_text = font.render("P1: " + str(p1.score), 1, (255, 0, 0))
            score1_text = font.render("P2: " + str(p2.score), 1, (255, 0, 0))
            screen.blit(score_text, (140, 360))
            screen.blit(score1_text, (140, 400))
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 20)
            continue_text = font.render(" Press C To Continue ", 1, (100, 100, 100))
            screen.blit(continue_text, (70, 470))

        else:
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 30)
            judge_text = font.render(" It's a Tie ", 1, (255, 0, 0))
            screen.blit(judge_text, (140, 320))
            score_text = font.render("P1: " + str(p1.score), 1, (255, 0, 0))
            score1_text = font.render("P2: " + str(p2.score), 1, (255, 0, 0))
            screen.blit(score_text, (140, 360))
            screen.blit(score1_text, (140, 400))
            font = pygame.font.Font('./diffusion/diffusion/ttf/diffusion-regular.ttf', 20)
            continue_text = font.render(" Press C To Continue ", 1, (100, 100, 100))
            screen.blit(continue_text, (70, 470))
    pygame.display.update()


def standing1(a, b):
    i = 19
    while (i > 15):

        if (
            a >= hitboxx[i] and a <= hitboxx[i] + hitboxwx[i] and
            b >= hitboxy[i] and b <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        elif (
            a + 25 >= hitboxx[i] and a + 25 <= hitboxx[i] + hitboxwx[i] and
            b + 20 >= hitboxy[i] and b + 20 <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        i = i - 1

    return True


def standing2(a, b):
    i = 15
    while (i > 11):
        if (
            a >= hitboxx[i] and a <= hitboxx[i] + hitboxwx[i] and
            b >= hitboxy[i] and b <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        elif (
            a + 25 >= hitboxx[i] and a + 25 <= hitboxx[i] + hitboxwx[i] and
            b + 20 >= hitboxy[i] and b + 20 <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        i = i - 1

    return True


def standing3(a, b):
    i = 7
    while (i > 3):
        if (
            a >= hitboxx[i] and a <= hitboxx[i] + hitboxwx[i] and
            b >= hitboxy[i] and b <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        elif (
            a + 25 >= hitboxx[i] and a + 25 <= hitboxx[i] + hitboxwx[i] and
            b + 20 >= hitboxy[i] and b + 20 <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        i = i - 1

    return True


def standing4(a, b):
    i = 11
    while (i > 7):
        if (
            a >= hitboxx[i] and a <= hitboxx[i] + hitboxwx[i] and
            b >= hitboxy[i] and b <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        elif (
            a + 25 >= hitboxx[i] and a + 25 <= hitboxx[i] + hitboxwx[i] and
            b + 20 >= hitboxy[i] and b + 20 <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        i = i - 1

    return True


def standing5(a, b):
    i = 3
    while (i > -1):
        if (
            a >= hitboxx[i] and a <= hitboxx[i] + hitboxwx[i] and
            b >= hitboxy[i] and b <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        elif (
            a + 25 >= hitboxx[i] and a + 25 <= hitboxx[i] + hitboxwx[i] and
            b + 20 >= hitboxy[i] and b + 20 <= hitboxy[i] + hitboxwy[i]
        ):
            return False
        i = i - 1

    return True


def ship1(a, b):
    if (
        a >= xship and a <= xship + 100 and
        b >= yship and b <= yship + 55
    ):
            return False
    elif (
        a + 25 >= xship and a + 25 <= xship + 100 and
        b + 20 >= yship and b + 20 <= yship + 55
    ):
            return False

    return True


def ship2(a, b):
    if (
        a >= xship2 and a <= xship2 + 130 and
        b >= yship2 and b <= yship2 + 40
    ):
            return False
    elif (
        a + 25 >= xship2 and a + 25 <= xship2 + 130 and
        b + 20 >= yship2 and b + 20 <= yship2 + 40
    ):
            return False

    return True


def ship3(a, b):
    if (
        a >= xship3 and a <= xship3 + 100 and
        b >= yship3 and b <= yship3 + 55
    ):
            return False
    elif (
        a + 25 >= xship3 and a + 25 <= xship3 + 100 and
        b + 20 >= yship3 and b + 20 <= yship3 + 55
    ):
            return False

    return True


def ship4(a, b):
    if (
        a >= xship4 + 10 and a <= xship4 + 95 and
        b >= yship4 and b <= yship4 + 70
    ):
            return False
    elif (
        a + 25 >= xship4 + 10 and a + 25 <= xship4 + 95 and
        b + 20 >= yship4 and b + 20 <= yship4 + 70
    ):
            return False

    return True


def ship5(a, b):
    if (
        a >= xship5 + 10 and a <= xship5 + 80 and
        b >= yship5 and b <= yship5 + 60
    ):
            return False
    elif (
        a + 25 >= xship5 + 10 and a + 25 <= xship5 + 80 and
        b + 20 >= yship5 and b + 20 <= yship5 + 60
    ):
            return False

    return True


def ship6(a, b):
    if (
        a >= xship6 and a <= xship6 + 130 and
        b >= yship6 and b <= yship6 + 40
    ):
            return False
    elif (
        a + 25 >= xship6 and a + 25 <= xship6 + 130 and
        b + 20 >= yship6 and b + 20 <= yship6 + 40
    ):
            return False

    return True

# main game loop
run = True
p1 = boot1(xchar1, ychar1, 1, 0, 0)
p2 = boot2(xchar2, ychar2, 1, 0, 0)
count = 0
count1 = 0
count2 = 0
count3 = 0
while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False

    if game_firstbg:
        keyss = pygame.key.get_pressed()
        if keyss[pygame.K_RETURN]:
            game_firstbg = False

    if k == 0 and not game_success and not game_died and not game_result and not game_firstbg:
        if count == 0:
            start = pygame.time.get_ticks()
        # right moving
        xship = ((xship + random.uniform(vellow[p1.level - 1], velhigh[p1.level - 1])) % 500.0)
        #  print(xship)
        xship2 = ((xship2 + random.uniform(vellow[p1.level - 1], velhigh[p1.level - 1])) % 500.0)
        xship3 = ((xship3 + random.uniform(vellow[p1.level - 1], velhigh[p1.level - 1])) % 500.0)
        xship6 = ((xship6 + random.uniform(vellow[p1.level - 1], velhigh[p1.level - 1])) % 500.0)

        # left moving
        xship4 = (xship4 - random.uniform(vellow[p1.level - 1], velhigh[p1.level - 1]))
        xship5 = (xship5 - random.uniform(vellow[p1.level - 1], velhigh[p1.level - 1]))
        if xship4 <= 0:
            xship4 = 420
        if xship5 <= 0:
            xship5 = 450

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and p1.xchar1 > 0:
            p1.xchar1 = p1.xchar1 - 1
        if keys[pygame.K_RIGHT] and p1.xchar1 + 1 < 470:
            p1.xchar1 = p1.xchar1 + 1
        if keys[pygame.K_UP] and p1.ychar1 > 0:
            p1.ychar1 = p1.ychar1 - 1
        if keys[pygame.K_DOWN] and p1.ychar1 + 1 < 680:
            p1.ychar1 = p1.ychar1 + 1

        if count > 0:
            k1 = standing1(p1.xchar1, p1.ychar1)
            k2 = standing2(p1.xchar1, p1.ychar1)
            k3 = standing3(p1.xchar1, p1.ychar1)
            k4 = standing4(p1.xchar1, p1.ychar1)
            k5 = standing5(p1.xchar1, p1.ychar1)
            kship1 = ship1(p1.xchar1, p1.ychar1)
            kship2 = ship2(p1.xchar1, p1.ychar1)
            kship3 = ship3(p1.xchar1, p1.ychar1)
            kship4 = ship4(p1.xchar1, p1.ychar1)
            kship5 = ship5(p1.xchar1, p1.ychar1)
            kship6 = ship6(p1.xchar1, p1.ychar1)

        if p1.ychar1 <= 700 and p1.ychar1 >= 590:
            p1.score = 0
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 590 and p1.ychar1 >= 530:
            p1.score = 10
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 530 and p1.ychar1 >= 480:
            p1.score = 15
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 480 and p1.ychar1 >= 420:
            p1.score = 25
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 420 and p1.ychar1 >= 360:
            p1.score = 30
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 360 and p1.ychar1 >= 300:
            p1.score = 40
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 300 and p1.ychar1 >= 250:
            p1.score = 45
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 250 and p1.ychar1 >= 190:
            p1.score = 55
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 190 and p1.ychar1 >= 130:
            p1.score = 60
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 130 and p1.ychar1 >= 80:
            p1.score = 70
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 80 and p1.ychar1 >= 15:
            p1.score = 75
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if p1.ychar1 <= 15 and p1.ychar1 >= 0:
            p1.score = 85
            end = pygame.time.get_ticks()
            p1.timebonus = 100 - (end - start)//1000
            p1.score = p1.score + p1.timebonus

        if count > 0:
            if p1.ychar1 <= 700 and p1.ychar1 >= 590 and not kship6:
                p1.score = 0
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
                game_died = True
            #  run = False

            if p1.ychar1 <= 590 and p1.ychar1 >= 530 and not k1 and kship6:
                p1.score = 10
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus

            # run = False
            if p1.ychar1 <= 530 and p1.ychar1 >= 480 and not kship5 and k1 and kship6:
                p1.score = 15
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if p1.ychar1 <= 480 and p1.ychar1 >= 420 and not k2 and kship5 and k1 and kship6:
                p1.score = 25
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 420 and p1.ychar1 >= 360 and
                not kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 30
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 360 and p1.ychar1 >= 300 and not k3 and
                kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 40
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 300 and p1.ychar1 >= 250 and not kship3 and k3 and
                kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 45
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 250 and p1.ychar1 >= 190 and not k2 and kship3 and
                k3 and kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 55
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 190 and p1.ychar1 >= 130 and not kship2 and k2 and kship3 and
                k3 and kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 60
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 130 and p1.ychar1 >= 80 and not k1 and kship2 and k2 and
                kship3 and k3 and kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 70
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if (
                p1.ychar1 <= 80 and p1.ychar1 >= 15 and not kship1 and k1 and kship2 and k2 and
                kship3 and k3 and kship4 and k2 and kship5 and k1 and kship6
            ):
                p1.score = 75
                game_died = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False

            if p1.ychar1 < 15 and p1.ychar1 >= 0:
                p1.score = 85
                game_success = True
                end = pygame.time.get_ticks()
                p1.timebonus = 100 - (end - start)//1000
                p1.score = p1.score + p1.timebonus
            # run = False
        count = count + 1

    if game_success or game_died and not game_firstbg:
        if not game_result:
            if count1 > 0:
                keys1 = pygame.key.get_pressed()
                if keys1[pygame.K_RETURN]:
                    if k == 0:
                        k = 1
                        p2.xchar2 = 250
                        p2.ychar2 = 5
                        # count = 0
                        # count1 = 0
                        count2 = 0
                        count3 = 0
                    elif k == 1:
                        game_result = True
                    #  print(game_result)
                        # print(k)
                    game_died = False
                    game_success = False
            count1 = count1 + 1

    if k == 1 and game_result and not game_firstbg:
        # print(count3)
        if count3 > 0:
            # print("hi")
            keys3 = pygame.key.get_pressed()
            if keys3[pygame.K_c]:
                # print("Hii")
                k = 0
                # print(k)
                p1.xchar1 = 250
                p1.ychar1 = 680
                count = 0
                count1 = 0
                # count2 = 0
                # count3 = 0
                game_died = False
                game_result = False
                game_success = False
                if p1.score > p2.score:
                    p1.level = p1.level + 1
                elif p2.score > p1.score:
                    p2.level = p2.level + 1
                else:
                    p2.level = p2.level + 1
                    p1.level = p1.level + 1
        count3 = count3 + 1

    if k == 1 and not game_success and not game_died and not game_result and not game_firstbg:
        if count2 == 0:
            start = pygame.time.get_ticks()
        # right moving
        # print("why")
        xship = ((xship + random.uniform(vellow[p2.level - 1], velhigh[p2.level - 1])) % 500)
        xship2 = ((xship2 + random.uniform(vellow[p2.level - 1], velhigh[p2.level - 1])) % 500)
        xship3 = ((xship3 + random.uniform(vellow[p2.level - 1], velhigh[p2.level - 1])) % 500)
        xship6 = ((xship6 + random.uniform(vellow[p2.level - 1], velhigh[p2.level - 1])) % 500)

        # left moving
        xship4 = (xship4 - random.uniform(vellow[p2.level - 1], velhigh[p2.level - 1]))
        xship5 = (xship5 - random.uniform(vellow[p2.level - 1], velhigh[p2.level - 1]))
        if xship4 <= 0:
            xship4 = 420
        if xship5 <= 0:
            xship5 = 450

        keys2 = pygame.key.get_pressed()
        if keys2[pygame.K_a] and p2.xchar2 > 0:
            p2.xchar2 = p2.xchar2 - 1
        if keys2[pygame.K_d] and p2.xchar2 + 1 < 470:
            p2.xchar2 = p2.xchar2 + 1
        if keys2[pygame.K_w] and p2.ychar2 > 0:
            p2.ychar2 = p2.ychar2 - 1
        if keys2[pygame.K_s] and p2.ychar2 + 1 < 680:
            p2.ychar2 = p2.ychar2 + 1

        if p2.ychar2 >= 0 and p2.ychar2 <= 80:
                p2.score = 0
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 80 and p2.ychar2 <= 130:
                p2.score = 10
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 130 and p2.ychar2 <= 190:
                p2.score = 15
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 190 and p2.ychar2 <= 250:
                p2.score = 25
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 250 and p2.ychar2 <= 300:
                p2.score = 30
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 300 and p2.ychar2 <= 360:
                p2.score = 40
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 360 and p2.ychar2 <= 420:
                p2.score = 45
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 420 and p2.ychar2 <= 480:
                p2.score = 55
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 480 and p2.ychar2 <= 530:
                p2.score = 60
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 530 and p2.ychar2 <= 590:
                p2.score = 70
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 590 and p2.ychar2 <= 670:
                p2.score = 75
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if p2.ychar2 >= 670 and p2.ychar2 <= 700:
                p2.score = 85
                end = pygame.time.get_ticks()
                p2.timebonus = 100 - (end - start)//1000
                p2.score = p2.score + p2.timebonus

        if count2 > 0:
            k11 = standing1(p2.xchar2, p2.ychar2)
            k22 = standing2(p2.xchar2, p2.ychar2)
            k33 = standing3(p2.xchar2, p2.ychar2)
            k44 = standing4(p2.xchar2, p2.ychar2)
            k55 = standing5(p2.xchar2, p2.ychar2)
            kship11 = ship1(p2.xchar2, p2.ychar2)
            kship22 = ship2(p2.xchar2, p2.ychar2)
            kship33 = ship3(p2.xchar2, p2.ychar2)
            kship44 = ship4(p2.xchar2, p2.ychar2)
            kship55 = ship5(p2.xchar2, p2.ychar2)
            kship66 = ship6(p2.xchar2, p2.ychar2)

        if count2 > 0:
            if p2.ychar2 >= 0 and p2.ychar2 <= 80 and not kship11:
                    p2.score = 0
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if p2.ychar2 >= 80 and p2.ychar2 <= 130 and kship11 and not k55:
                    p2.score = 10
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if p2.ychar2 >= 130 and p2.ychar2 <= 190 and kship11 and k55 and not kship22:
                    p2.score = 15
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if p2.ychar2 >= 190 and p2.ychar2 <= 250 and kship11 and k55 and kship22 and not k44:
                    p2.score = 25
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 250 and p2.ychar2 <= 300 and kship11 and
                k55 and kship22 and k44 and not kship33
            ):
                    p2.score = 30
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 300 and p2.ychar2 <= 360 and kship11 and
                k55 and kship22 and k44 and kship33 and not k33
            ):
                    p2.score = 40
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 360 and p2.ychar2 <= 420 and kship11 and k55 and
                kship22 and k44 and kship33 and k33 and not kship44
            ):
                    p2.score = 45
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 420 and p2.ychar2 <= 480 and kship11 and k55 and kship22 and
                k44 and kship33 and k33 and kship44 and not k22
            ):
                    p2.score = 55
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 480 and p2.ychar2 <= 530 and kship11 and k55 and kship22 and
                k44 and kship33 and k33 and kship44 and
                k22 and not kship55
            ):
                    p2.score = 60
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 530 and p2.ychar2 <= 590 and kship11 and k55 and kship22 and k44 and
                kship33 and k33 and kship44 and k22 and kship55 and not k11
            ):
                    p2.score = 70
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 590 and p2.ychar2 <= 670 and
                kship11 and k55 and kship22 and k44 and kship33 and
                k33 and kship44 and k22 and kship55 and k11 and not kship66
            ):
                    p2.score = 75
                    game_died = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

            if (
                p2.ychar2 >= 670 and p2.ychar2 <= 700 and kship11 and k55 and kship22 and k44 and
                kship33 and k33 and kship44 and k22 and kship55 and k11 and kship66
            ):
                    p2.score = 85
                    game_success = True
                    end = pygame.time.get_ticks()
                    p2.timebonus = 100 - (end - start)//1000
                    p2.score = p2.score + p2.timebonus

        count2 = count2 + 1
    redrawGameWindow()
pygame.quit()
