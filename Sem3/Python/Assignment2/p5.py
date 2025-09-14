#Program to calculate Compound Interest with log function
import math
try:
    p=float(input("Enter the Principal Amount: "))
    r=float(input("Enter the Annual Rate of interest: "))
    t=int(input("Enter Time (in years): "))

    A = p*math.exp(t*math.log(1 + r/100))
    print(f"Compound Interest: {A-p}\nTotal Amount: {A}")
except ValueError:
    print("Invalid Input")