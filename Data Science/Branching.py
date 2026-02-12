#premature termination of loop
memory=16
if memory<16:
    print("Insufficient memory")
    raise Exception()

#Decision flow and branching code execution in Python
marks={
    "Maths":float(input("Enter your marks in Maths:")),
    "Science":float(input("Enter your marks in Science:")), 
    "English":float(input("Enter your marks in English:")),
    "Nepali":float(input("Enter your marks in Nepali:"))
}

total_marks=float(input("Enter the full marks of the subject:"))
sum_total=total_marks*4
total=0
for mark in marks:
    total+=marks[mark]
percentage=(total/sum_total)*100
rounded_percentage=round(percentage,2)
print(f"You got {percentage}%.")

#if elseif else 
if percentage>90:
    print("A+")
elif percentage>80:
    print("A")
elif percentage>70:
    print("B+")
elif percentage>60:
    print("B")
elif percentage>50:  
    print("C+")
else:
    print("Fail")


#While loops
number=int(input("Enter a number you want to calculate factorial of:"))
n=1
fact=1

while(n<=number):
    fact=fact*n
    n=n+1
    
print(f"The factorial of {number} is {fact}.")