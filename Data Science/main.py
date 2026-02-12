# name=input("Enter your name:")
# age=int(input("Enter your age:"))
# married=bool(input("Are you married (True/False):"))
# salary=float(input("Enter your salary:"))

# print(name)
# print(age)
# print(married)
# print(salary)
# print(type(name))
# print(type(age))
# print(type(married))
# print(type(salary))

# message=f"""
#     My name is {name}.
#     Age is {age}.
#     Me being married is {married}
#     My salary is {salary}."""
    
# print(message)

sub1=input("Enter name of subject:")
sub2=input("Enter name of subject:")
sub3=input("Enter name of subject:")
sub4=input("Enter name of subject:")
mark1=float(input(f"Enter marks of {sub1}:"))
mark2=float(input(f"Enter marks of {sub2}:"))
mark3=float(input(f"Enter marks of {sub3}:"))
mark4=float(input(f"Enter marks of {sub4}:"))

total_marks=float(input("Enter the full marks of the subject:"))
sum_total=total_marks*4
total=mark1+mark2+mark3+mark4
percentage=(total/sum_total)*100
print(f"You got {percentage}%.")