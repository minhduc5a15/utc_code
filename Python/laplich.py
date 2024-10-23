arr = []
for _ in range(int(input())):
    y, x = map(int, input().split())
    arr.append((x, y))
arr.sort(key=lambda x: x[0])
count, d = 0, 0
for x, y in arr:
    if y > d:
        count += 1
        d = x
print(count)
