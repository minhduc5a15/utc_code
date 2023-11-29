n, s, point = int(input()), input(), 0
for char in s:
    point += 1 if char == 't' else 3 if char == 'M' or char == 'T' else 5 if char == 'X' else 9 if char == 'H' else 0
print(point) 
    