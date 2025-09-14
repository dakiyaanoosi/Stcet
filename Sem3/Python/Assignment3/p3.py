#Program to convert temperature from Celcius to Fahrenheit and vice versa
try:
    unit = input("Convert the temperature from [C/F]: ").lower()
    if(unit == 'c'):
        tempC = float(input("Enter the temperature in Centigrade: "))
        tempF = (tempC*(9/5))+32
        print(f"Temperature in Fahrenheit: {tempF: .2f}")
    elif(unit == 'f'):
        tempF = float(input("Enter the temperature in Fahrenheit: "))
        tempC = (tempF-32)*(5/9)
        print(f"Temperature in Centigrade: {tempC: .2f}")
    else:
        print("Invalid Input")
except ValueError:
    print("Invalid Input!")