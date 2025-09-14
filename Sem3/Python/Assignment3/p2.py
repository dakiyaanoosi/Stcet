#Pay Compuatation

try:
    hours=int(input("Enter the hours worked: "))
    rate=int(input("Enter the hourly pay rate: "))
    if(hours>40):
        overtime=hours-40
        pay=(40*rate)+(overtime*rate*1.5)
    else:
        pay=(hours*rate)
    print("Total pay:",pay)
    
except:
    print("Invalid Input!")