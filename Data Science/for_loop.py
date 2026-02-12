# names=["Alice", "Bob", "Charlie", "Diana"]
# for name in names:
#     print("Hello, " + name + "!")
    
# #number of times
# # range(starting,stopping,stepping)
# for i in range(10):
#     print(i)
    
# for i in range(10,20):
#     print(i)
    
# for i in range(10,30,5):
#     print(i)

# num_list=range(1,11)
# print(num_list)

# for index in num_list:
#     print(index)

# number_of_subjects=int(input("Enter number of subjects:"))
# marks=[]
# for i in range(number_of_subjects):
#     mark=float(input(f"Enter marks of subject {i+1}:"))
#     marks.append(mark)
    
# total_marks=int(input("Enter full marks of one subject:"))
# total=0
# for mark in marks:
#     total+=mark
    
# percentage=(total/total_marks)*100
# rounded_percentage=round(percentage,2)
# print(f"You got {percentage}%.")

# #if elseif else 
# if percentage>90:
#     print("A+")
# elif percentage>80:
#     print("A")
# elif percentage>70:
#     print("B+")
# elif percentage>60:
#     print("B")
# elif percentage>50:  
#     print("C+")
# else:
#     print("Fail")


# for enumerate
# subjects=["Maths","Science","English"]
# marks=[40,60,70]

# for i,v in enumerate(subjects):
#     mark=marks[i]
#     name=v
#     print(f"The marks of {name} is {mark}")

# student={
#     "name":"John",
#     "age":20,
#     "address":"Kathmandu",
#     "blood-group":"A+",
#     "section":"A2",
#     "course":"Economics"
# }


# for key in student.keys():
#     value=student[key]
#     print(f"The {key} of student is {value}")
    
# for key,value in student.items():
#     print(f"The {key} of student is {value}")
    
# for key in student:
#     print(f"The {key} of student is {student[key]}")


# conversions=[]
# marks=[45,67,89,78,90]
# for mark in marks:
#     conversion=mark/100
#     conversions.append(conversion)
# print(conversions)

# conversions=[x/100 for x in marks] another way of writing above code
# print(conversions)

# passed=[]
# marks=[40,67,89,78,90]
# for mark in marks:
#     if mark> 40:
#         passed.append(True)
#     else:
#         passed.append(False)    
# print(passed)

# passed=[True if x>40 else False for x in marks]#another way if writing above code
# print(passed)

odd_or_even=[]
numbers=[10,23,45,66,78,91]
# odd_or_even=["Even" if x%2==0 else "Odd" for x in numbers]

for n in numbers:
    if n%2==0:
        odd_or_even.append("Even")
    else:
        odd_or_even.append("Odd")    
print(odd_or_even)