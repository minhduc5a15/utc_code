n = int(input())
arr = [1.0, 1.2, 1.7, 2.2]
d = [100, 150, 250, 500]
count = 0
for i in range(4):
    if n > d[i]:
        n -= d[i]
        count += 1
res = 0
if count == 0:
    res = n * arr[0]
    print(f"{res:.3f}")
else:
    for i in range(count):
        res += arr[i] * d[i]
    res += n * arr[count]
    print(f"{res:.3f}")