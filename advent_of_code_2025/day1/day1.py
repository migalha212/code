f = open("input.txt")
password = 0
dial = 50
val = 0

for line in f:
    line = line.strip()
    direction = line[0]
    val = int(line[1::])
    
    full, partial = divmod(val, 100)
    
    password += full
    
    delta = -partial if direction == 'L' else partial
    next_position = dial + delta
    
    if dial != 0:
        if direction == "L" and next_position <= 0:
            password += 1
        elif direction == "R" and next_position >= 100:
            password += 1
    
    dial = next_position % 100

print(int(password))

f.close