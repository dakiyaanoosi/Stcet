#Program to calculate area of a triangle where the 3 sides are given
import math
try:
    a=float(input("Enter the 1st side: "))
    b=float(input("Enter the 2nd side: "))
    c=float(input("Enter the 3rd side: "))
    if(a+b>c and a+c>b and b+c>a):
        S=(a+b+c)/2
        A=math.sqrt(S*(S-a)*(S-b)*(S-c))
        print(f"Area: {A:.2f}")
    else:
        print("Invalid triangle!")
except ValueError:
    print("Invalid Input!")