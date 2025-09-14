#Patterns

try:
    n=int(input("Enter the number of rows: "))
    print("\nPattern 1\n")
    for i in range (n):
        for j in range (i+1):
            print("*", end=" ")
        print()

    print("\nPattern 2\n")
    for i in range (n):
        for j in range (n-i-1):
            print("  ", end="")
        for k in range (i+1):
            print("*", end=" ")
        print()

    print("\nPattern 3\n")
    for i in range (n):
        for j in range (n-i-1):
            print(" ", end="")
        for k in range (i+1):
            print("*", end=" ")
        print()

    print("\nPattern 4\n")
    for i in range (n, 0, -1):
        for j in range (n-i):
            print(" ", end="")
        for j in range (i):
            print("*", end=" ")
        print()
except:
    print("Invalid Input!")