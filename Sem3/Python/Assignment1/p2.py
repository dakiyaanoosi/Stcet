#Program to change temperature from Centigrade to Fahrenheit.

try:
    tempC = float(input("Enter the temperature in Centigrade: "))
    tempF = (tempC*(9/5))+32
    print(f"Temperature in Fahrenheit: {tempF: .2f}")
except ValueError:
    print("Invalid input!")