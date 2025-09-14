#Program to find the max and min of 3 numbers
try:
    a = int(input("Enter the 1st number: "))
    b = int(input("Enter the 2nd number: "))
    c = int(input("Enter the 3rd number: "))
    #Finding max
    if(a>b):
        if(a>c):
            maximum=a
        else:
            maximum=c
    elif(b>c):
        maximum=b
    else:
        maximum=c
    
    #Finding min
    if(a<b):
        if(a<c):
            minimum=a
        else:
            minimum=c
    elif(b<c):
        minimum=b
    else:
        minimum=c
    
    if(minimum==maximum):
        print("All the numbers are equal!")
    else:
        print(f"Min: {minimum}\nMax: {maximum}")
except ValueError:
    print("Invalid Input!")