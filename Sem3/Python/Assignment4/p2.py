#Program to check if the number is prime or not
try:
    n=int(input("Enter a number: "))
    if(n<=1):
        print(f"{n} is Not a prime number!")
    else:
        isPrime=True
        for i in range(2,n):
            if(n%i==0):
                isPrime=False
                break
        if(isPrime):
            print(f"{n} is a Prime number!")
        else:
            print(f"{n} is Not a prime number!")

except ValueError:
    print("Invalid Input!")