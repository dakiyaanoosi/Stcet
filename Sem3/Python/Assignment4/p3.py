#Program to find Armstrong numbers in the range (1, 1000)
for i in range (1, 1000):
    if(i<10):
        print(i)
    elif(i>=10 and i<=99):
        num=i
        newNum=(num//10)**2 + (num%10)**2
        if(newNum==i):
            print(i)
    else:
        num=i
        newNum=(num%10)**3 + ((num//10)%10)**3 + ((num//10)//10)**3
        if(newNum==i):
            print(i)