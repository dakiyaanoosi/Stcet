#Program to find the max and min of 3 numbers
try:
    a = int(input("Enter the 1st number: "))
    b = int(input("Enter the 2nd number: "))
    c = int(input("Enter the 3rd number: "))

    #Finding max
    maximum = max(a, b, c)
    
    #Finding min
    minimum = min(a, b, c)
    
    if(minimum==maximum):
        print("All the numbers are equal!")
    else:
        print(f"Min: {minimum}\nMax: {maximum}")
except ValueError:
    print("Invalid Input!")