n = int(input())
arr = list(map(int, input().split()))
x = float(input())
res = 0
for i in range(1, n + 1):
    res += arr[i] * i * (x ** (i - 1))
print("{:.3f}".format(round(res, 3)))
