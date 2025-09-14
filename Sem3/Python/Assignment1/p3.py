#Program to change temperature from Fahrenheit to Centigrade.

try:
    tempF = float(input("Enter the temperature in Fahrenheit: "))
    tempC = (tempF-32)*(5/9)
    print(f"Temperature in Centigrade: {tempC: .2f}")
except ValueError:
    print("Invalid input!")