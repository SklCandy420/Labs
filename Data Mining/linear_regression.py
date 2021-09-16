from statistics import mean
import numpy as np
import matplotlib.pyplot as pt
from matplotlib import style
import random


def create_dataset(n, variance, corr=True):
    val = 1
    y_val = []
    x_val = []
    for i in range(n):
        y = val + random.randrange(-variance, variance)
        y_val.append(y)
        if corr:
            val += 5
        else:
            val -= 5
        x_val.append(i)
    return np.array(x_val, dtype=np.float64), np.array(y_val, dtype=np.float64)


x_val, y_val = create_dataset(50, 10)


def best_slope(xs, ys):
    slope = mean(xs) * mean(ys)
    slope = slope - mean(xs * ys)
    slope = slope / ((mean(xs) * mean(xs)) - mean(xs * xs))
    return slope


m = best_slope(x_val, y_val)

pt.scatter(x_val, y_val)


def y_intercept(xs, ys, m):
    b = mean(ys) - (m * mean(xs))
    return b


b = y_intercept(x_val, y_val, m)

reg_line = [(m * x) + b for x in x_val]


def err_square(ys_o, ys_l):
    return sum((ys_l - ys_o) ** 2)


def cof_det(ys_o, ys_l):
    ym = [mean(ys_o) for y in ys_o]
    ers = err_square(ys_o, ys_l)
    erm = err_square(ys_o, ym)
    return 1 - (ers / erm)


conf = cof_det(y_val, reg_line)

print(conf)

pt.plot(x_val, reg_line, color="r")
pt.show()