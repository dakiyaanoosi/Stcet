#Program to check if the number is positive or negative
try:
    n = int(input("Enter a number: "))
    if(n<0):
        print(f"{n} is a Negative number!")
    elif(n>=0):
        print(f"{n} is a Positive number!")
except ValueError:
    print("Invalid Input!")