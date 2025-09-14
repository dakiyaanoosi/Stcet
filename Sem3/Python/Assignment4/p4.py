#Program to find Prime numbers in the range (1, 1000)
for i in range (2, 1000):
    isPrime=True
    for j in range(2,i):
        if(i%j==0):
            isPrime=False
            break
    if(isPrime):
        print(i)