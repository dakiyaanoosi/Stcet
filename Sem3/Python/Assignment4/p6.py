#Program to repeatedly take input from the user. If the user enters "done", stop taking input and print sum of all the numbers he entered
print("INSTRUCTION: Type 'Done' to display the Sum of numbers!")
inp=input("Enter a number: ")
sum=0
while(inp.lower()!='done'):
    try:
        num=int(inp)
        sum+=num
    except ValueError:
        print("Invalid Input!", end=" ")
    inp=input("Enter a number: ")

print("\nSum of numbers:",sum)