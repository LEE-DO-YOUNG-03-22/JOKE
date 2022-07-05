from turtle import *
import random, mouse

ht()
bgcolor("black")
speed(0)
SL=0
def segment():
    for x in range(8):
        fd(SL)
        lt(225)

def loop():
    global SL
    SL = random.randrange(30,121)
    r = random.random()
    g = random.random()
    b = random.random()
    color(r, g, b)
    for z in range(8):
        segment()
        rt(60)

def screenLeftClick(x, y):
    penup()
    goto(x,y)
    pendown()
    loop()

onscreenclick(screenLeftClick,1)
done()
