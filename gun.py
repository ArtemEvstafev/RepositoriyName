from random import randrange as rnd, choice
import tkinter as tk
import math
import time

# print (dir(math))

root = tk.Tk()
fr = tk.Frame(root)
root.geometry('800x600')
canv = tk.Canvas(root, bg='white')
canv.pack(fill=tk.BOTH, expand=1)
TARGETS_NUMBER = 1


class ball():
    def __init__(self, x=40, y=450):
        """ Конструктор класса ball

        Args:
        x - начальное положение мяча по горизонтали
        y - начальное положение мяча по вертикали
        """
        self.x = x
        self.y = y
        self.a = 1
        self.r = 10
        self.vx = 0
        self.vy = 0
        self.color = choice(['blue', 'green', 'red', 'brown', 'black'])
        self.id = canv.create_oval(
            self.x - self.r,
            self.y - self.r,
            self.x + self.r,
            self.y + self.r,
            fill=self.color
        )
        self.live = 30

    def set_coords(self):
        canv.coords(
            self.id,
            self.x - self.r,
            self.y - self.r,
            self.x + self.r,
            self.y + self.r
        )

    def move(self):
        """Переместить мяч по прошествии единицы времени.

        Метод описывает перемещение мяча за один кадр перерисовки. То есть, обновляет значения
        self.x и self.y с учетом скоростей self.vx и self.vy, силы гравитации, действующей на мяч,
        и стен по краям окна (размер окна 800х600).
        """

        if ((self.x + self.r >= 800 or self.x - self.r <= 0) and self.vx > 0):
            self.vx *= -0.8
        if ((self.y + self.r >= 590 - 2 * self.r or self.y - self.r <= 0) and self.vy > 0):
            self.vy *= -0.8
        if ((self.y + self.r >= 600)):
            self.vy = 0
            self.a = 0
        self.vy += self.a  # 0.08*abs(self.vy)
        self.vx -= 0.01 * self.vx
        self.x += self.vx
        self.y += self.vy

    def hittest(self, obj):
        """Функция проверяет сталкивалкивается ли данный обьект с целью, описываемой в обьекте obj.

        Args:
            obj: Обьект, с которым проверяется столкновение.
        Returns:
            Возвращает True в случае столкновения мяча и цели. В противном случае возвращает False.
        """
        if (((self.x - obj.x) ** 2 + (self.y - obj.y) ** 2) ** 0.5 <= self.r + obj.r):
            return True
        else:
            return False


class gun():
    def __init__(self):
        self.f2_power = 10
        self.f2_on = 0
        self.an = 1
        self.id = canv.create_line(20, 450, 50, 420, width=7)

    def fire2_start(self, event):
        self.f2_on = 1

    def fire2_end(self, event):
        """Выстрел мячом.

        Происходит при отпускании кнопки мыши.
        Начальные значения компонент скорости мяча vx и vy зависят от положения мыши.
        """
        global balls, bullet
        bullet += 1
        new_ball = ball()
        new_ball.r += 5
        self.an = math.atan((event.y - new_ball.y) / (event.x - new_ball.x))
        new_ball.vx = self.f2_power * math.cos(self.an)
        new_ball.vy = self.f2_power * math.sin(self.an)
        balls += [new_ball]
        self.f2_on = 0
        self.f2_power = 10

    def targetting(self, event=0):
        """Прицеливание. Зависит от положения мыши."""
        if event:
            self.an = math.atan((event.y - 450) / (event.x - 20))
        if self.f2_on:
            canv.itemconfig(self.id, fill='orange')
        else:
            canv.itemconfig(self.id, fill='black')
        canv.coords(self.id, 20, 450,
                    20 + max(self.f2_power, 20) * math.cos(self.an),
                    450 + max(self.f2_power, 20) * math.sin(self.an)
                    )

    def power_up(self):
        if self.f2_on:
            if self.f2_power < 100:
                self.f2_power += 1
            canv.itemconfig(self.id, fill='orange')
        else:
            canv.itemconfig(self.id, fill='black')


class target():
    def __init__(self):
        # self.points = 0
        global points
        self.live = 1
        self.id = canv.create_oval(0, 0, 0, 0)
        self.id_points = canv.create_text(30, 30, text=points, font='28')  # text=self.points
        self.new_target()

    def new_target(self):
        """ Инициализация новой цели. """
        x = self.x = rnd(600, 780)
        y = self.y = rnd(300, 550)
        r = self.r = rnd(2, 50)
        self.a = choice([1, -1, 2, -2, 3, -3])
        color = self.color = 'red'
        canv.coords(self.id, x - r, y - r, x + r, y + r)
        canv.itemconfig(self.id, fill=color)

    def hit(self):
        """Попадание шарика в цель."""
        global points
        canv.coords(self.id, -10, -10, -10, -10)
        points += 1
        canv.itemconfig(self.id_points, text=points)

    def move(self):
        """Переместить мишегь по прошествии единицы времени.
        """
        if ((self.y - self.r) >= 600):
            self.y = 0 + self.r
        if (self.y + self.r <= 0):
            self.y = 600 + self.y
        self.y += self.a

    def set_coords(self):
        x = self.x
        y = self.y
        r = self.r
        canv.coords(self.id, x - r, y - r, x + r, y + r)


points = 0
targets = []  # массив мишеней
for t in range(0, TARGETS_NUMBER):
    targets.append(target())

screen1 = canv.create_text(400, 300, text='', font='28')
g1 = gun()
bullet = 0
balls = []
lives = 1  # важная вещь для проверки на стлокновение


def new_game(event=''):  # основной цикл
    global gun, targets, lives, screen1, balls, bullet  # t1

    for t in targets:  # создаем новые цел в игре
        t.new_target()
        t.live = 1
    lives = 1
    canv.itemconfig(screen1, text='')
    bullet = 0
    balls = []
    canv.bind('<Button-1>', g1.fire2_start)  # эти три строчки отвечают за пушку
    canv.bind('<ButtonRelease-1>', g1.fire2_end)
    canv.bind('<Motion>', g1.targetting)
    z = 3
    while (lives == 1 or balls):
        for t in targets:
            t.move()
            t.set_coords()
        for b in balls:  # для движения мячей нужен данный цикл
            b.move()
            b.set_coords()
            for t in targets:
                if b.hittest(t) and t.live:  # данное условие выполняется при столкновении
                    for b in balls:  # удаляем все мячи
                        canv.delete(b.id)
                    lives = 0
                    t.hit()  # мяч попал, поэтому нужно сделать вот это
                    canv.bind('<Button-1>', '')
                    canv.bind('<ButtonRelease-1>', '')
                    canv.itemconfig(screen1, text='Вы уничтожили цель за ' + str(bullet) + ' выстрелов')
                    canv.update()
                    time.sleep(z)
                    new_game()
        canv.update()
        time.sleep(0.03)
        g1.targetting()
        g1.power_up()
    canv.itemconfig(screen1, text='')
    canv.delete(gun)
    root.after(750, new_game)


new_game()

# mainloop()
