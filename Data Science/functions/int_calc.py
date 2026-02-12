from class1 import interest

principle=float(input("Enter the principle amount:"))
rate=float(input("Enter the rate amount:"))
time=float(input("Enter the time:"))
currency=input("Enter the currency (default is NPR):")
simple_interest=interest(principle,time,rate,currency)
print(f"The simple interest is {simple_interest}")