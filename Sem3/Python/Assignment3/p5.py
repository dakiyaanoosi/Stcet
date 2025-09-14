#Program to check if the number is even or odd
try:
    n = int(input("Enter a number: "))
    if(n%2==0):
        print(f"{n} is an Even number!")
    else:
        print(f"{n} is an Odd number!")
except ValueError:
    print("Invalid Input!")