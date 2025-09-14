#Program to repeatedly take input from the user. If the user enters "done", stop taking input and print the max, min and avg of all the numbers entered

print("INSTRUCTION: Type 'Done' to display the Max, Min & Average of all the numbers!")
inp=input("Enter a number: ")
maximum=minimum=None
count=sum=0
while(inp.lower()!='done'):
    try:
        num=int(inp)
        if(maximum==None and minimum==None):
            maximum=minimum=num
        elif(num>maximum):
            maximum=num
        elif(num<minimum):
            minimum=num
        count+=1
        sum+=num
    except ValueError:
        print("Invalid Input!", end=" ")
    inp=input("Enter a number: ")

print(f"Max: {maximum}\nMin: {minimum}\nAverage: {sum/count}")