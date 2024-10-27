n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.insert(0, -1)
check = False
for i in range(1, n):
    if arr[i - 1] == k or arr[i + 1] == k:
        print(i, end=" ")
        check = True
if not check: print(-1)
