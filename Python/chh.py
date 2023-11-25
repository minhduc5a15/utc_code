s = input()

count = {}
for char in s:
    if char in count: count[char] += 1
    else: count[char] = 1
check = True
for item in count.values():
    if item % 2 != 0: 
        check = False
print("Yes" if check else "No")