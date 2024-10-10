n = int(input("n:"))
i = 0
high = 0
sechigh = 0

while i < n:
    x = int(input(f"value {i+1}:"))
    if x >= high:
        high = x
    elif x >= sechigh:
        sechigh = x
    i += 1
    
print(f"Highest value = {high} 2nd. Highest value = {sechigh}")