n, x = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()

res = 1

for i in range(1, n):
    if arr[i - 1] + arr[i] <= x:
        res = i + 1
    else: break

print(res)