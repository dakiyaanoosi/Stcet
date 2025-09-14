#Progran to find GCD of two numbers using Euclid's algorithm
try:
    a=int(input("Enter the 1st number: "))
    b=int(input("Enter the 2nd number: "))
    
    while(a!=0):
        a,b=b%a,a
    print("GCD:",b)

except ValueError:
    print("Invalid Input!")