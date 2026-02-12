# functions in python
# function signatures
    # name of function
    # no of inputs
    # type of inputoutput/no of returns
    
# def <name>(parameters...): function defining
    # ......
    # return ...
    
# SOLID Principle - Single Responsibility,open/closed, Liskov Substitution, Interface Segregation, Dependency Inversion
# KISS Principle - Keep It Simple Stupid
# DRY Principle - Don't Repeat Yourself
    
# def add(a,b):
#     return a+b

# def product(a,b):
#     print(f"The eproduct of two numbers is {a*b}")


# num1=int(input(("Enter first number:")))
# num2=int(input(("Enter second number:")))

# print(f"The sum of two numbers is {add(num1,num2)}")
# product(num1,num2)
    
def interest(p,t,r,currency="NPR"):
    if currency!="NPR":
        exchange_rate=float(input("Enter the exchange rate:"))
        p=p*exchange_rate
    si=(p*t*r)/100
    return si

principle=float(input("Enter the principle amount:"))
rate=float(input("Enter the rate amount:"))
time=float(input("Enter the time:"))
currency=input("Enter the currency (default is NPR):")
simple_interest=interest(principle,time,rate,currency)
print(f"The simple interest is {simple_interest}")



