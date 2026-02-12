# List
marks=[10,20,30,"hello",50]
print(marks)
print(marks[-1])
print(marks[4])
marks.append(60)
marks[3]=40
print(marks)
marks.pop(4)
marks.remove(40)
print(marks)
print(type(marks))
#tuple
marks=(10,20,30,40,50)
print(marks)
print(type(marks))

#dictionary
a={"name":"Ram","age":25,"salary":50000,"married":False}
print(a)
a["age"]=26
print(a["age"])
a["address"]="Kathmandu"
print(a)
del a["married"]
print(a)

l=[[1,2,3],[4,5,6],[7,8,9]]
print(l[0][1])