# Program to compare two numbers

try:
    a=int(input("Enter 1st number: "))
    b=int(input("Enter 2nd number: "))
    if(a>b):
        print(f"{a} is Greater than {b}!")
    elif(a<b):
        print(f"{a} is Less than {b}!")
    else:
        print("Both numbers are Equal!")
except ValueError:
    print("Invalid Input!")