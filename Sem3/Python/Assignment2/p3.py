#Program to find the 3rd side and the remaining 2 angles of a triangle when 2 of the slides and one angle is given
import math
try:
    b=float(input("Enter the side 'b': "))
    c=float(input("Enter the side 'c': "))
    A=int(input("Enter the angle A (in degrees): "))
    A=math.radians(A)

    a=math.sqrt(b**2 + c**2 - 2*b*c*math.cos(A))
    B=math.asin((b*math.sin(A))/a)
    C=math.asin((c*math.sin(A))/a)

    B,C=math.degrees(B), math.degrees(C)
    print(f"Side 'a': {a:.2f}\nAngle 'B': {int(B)}\nAngle 'C': {int(C)}")

except ValueError:
    print("Invalid Input!")