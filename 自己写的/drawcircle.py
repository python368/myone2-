import math
import turtle
# 使用模块turtle绘制圆
def drawCircleTurtle(x, y, r):
    # 移到起点
    turtle.up()
    turtle.setpos(x + r, y)
    turtle.down()
    # 绘制圆
    for i in range(0, 365, 5):
        a = math.radians(i)
        turtle.setpos(x + r*math.cos(a), y + r*math.sin(a))

drawCircleTurtle(100, 100, 50)
turtle.mainloop()