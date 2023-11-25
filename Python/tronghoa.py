n, f = map(int, input().split())
arr = list(map(int, input().split()))
pos = []
count = 0
arr.append(2)
for item in arr:
    if item == 0:
        count += 1
    else:
        pos.append(count)
        count = 0
for item in pos:
    f -= int((item - 1) / 2) 
    if f <= 0: break
print("NO" if f > 0 else "YES")