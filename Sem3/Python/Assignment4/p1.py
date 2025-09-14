#Program to find the sum of n numbers
try:
    n=int(input("How many numbers you want to add: "))
    sum=0
    print(f"Enter the {n} numbers")
    for i in range (n):
        num=int(input())
        sum+=num
    print("Sum of numbers:",sum)
except ValueError:
    print("Invalid Input!")