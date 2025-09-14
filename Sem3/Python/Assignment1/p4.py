#Program to calculate the Simple & Compund Interest and the Final Amount

try:
    p=float(input("Enter the Principal Amount: "))
    r=float(input("Enter the Annual Rate of Interest: "))
    t=int(input("Enter Time (in years): "))

    SI=(p*r*t)/100
    CI=p*(1+r/100)**t

    print(f"\nSimple Interest: {SI}\nTotal Amount: {p+SI}\n")
    print(f"Compound Interest: {CI-p}\nTotal Amount: {CI}")

except ValueError:
    print("Invalid Input")