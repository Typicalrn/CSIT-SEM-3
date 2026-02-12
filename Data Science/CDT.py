print("Enter your information:")
name=input("Enter your name:")
city=input("City:")
district=input("District:")
ward=input("Ward:")
salary=float(input("Salary:"))
marks=float(input("Marks:"))

Info={
    "Name":name,
    "Address":{
        "City":city,
        "District":district,
        "Ward":ward
    },
    "Salary":salary,
    "Marks":marks
}

print(f"Your information is:{Info}")