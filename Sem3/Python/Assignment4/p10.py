#Patterns

try:
    n=int(input("Enter the number of rows: "))
    print("\nPattern 1\n")
    for i in range (n):
        print("* "*(i+1))

    print("\nPattern 2\n")
    for i in range (n):
        print("  "*(n-i-1)+"* "*(i+1))

    print("\nPattern 3\n")
    for i in range (n):
        print(" "*(n-i-1)+"* "*(i+1))

    print("\nPattern 4\n")
    for i in range (n, 0, -1):
        print(" "*(n-i)+"* "*i)
        
except ValueError:
    print("Invalid Input!")