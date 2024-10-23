input()
res, count = 0, 0
for num in list(map(int, input().split())):
    if num == 0:
        count += 1
        res = max(res, count)
    else:
        count = 0

print(res)
