#Program to calculate the area of a sphere
import math
try:
    r=float(input("Enter radius of the Sphere: "))
    A=4*math.pi*r**2
    print(f"Area: {A:.2f}")
except ValueError:
    print("Invalid Input!")
