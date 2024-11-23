first = int(input("value1:"))
second = int(input("value2:"))
i = 1
res = 0
while i <= second and i <=first:
    if(second % i == 0 and first % i == 0):
        res = i
            
    i += 1



print(f"the greatest common factor of {first} and {second} is {res}")