print("Hello, World!")
x, y, z = "Orange", "Banana", "Cherry"
print(x)
print(y)
print(z)


for x in "banana":
  print(x)

b = "Hello, World!"
print(b[-5:-2])

a = "Hello, World!"
print(a.split(",")) # returns ['Hello', ' World!']

fruits = ["apple", "banana", "cherry", "kiwi", "mango"]

newlist = [x for x in fruits if "a" in x]

print(newlist)

a = 200
b = 33
if b > a:
  print("b is greater than a")
elif a == b:
  print("a and b are equal")
else:
  print("a is greater than b")
  print(a)
i = 1
while i < 6:
  print(i)
  if i == 3:
    break
  i += 1

