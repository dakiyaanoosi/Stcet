#Program to find Eucledian distance b/w to points
import math
try:
    x1=float(input("x1: "))
    y1=float(input("y1: "))
    x2=float(input("x2: "))
    y2=float(input("y2: "))

    dist=math.sqrt((x2-x1)**2 + (y2-y1)**2)
    print("Eculedian distance:",dist)
except ValueError:
    print("Invalid Input!")