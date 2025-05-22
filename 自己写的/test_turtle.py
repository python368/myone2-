import turtle

def draw_tringle(x1, y1, x2, y2, x3, y3, t):
    #尝试绘制一个三角形
    t.up()
    t.setpos(x1, y1)
    t.down()
    t.setpos(x2, y2)
    t.setpos(x3, y3)
    t.setpos(x1, y1)
    t.up()

def main():
    print('testing turtle graphics...')
    t = turtle.Turtle()
    t.hideturtle()
    draw_tringle(-100, 0, 0, -173.2, 100, 0, t)
    turtle.mainloop()
#调用main()函数
if __name__ == '__main__':
    main()