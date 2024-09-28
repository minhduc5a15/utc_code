arr = list(map(int, input().split()))
if 1 not in arr: print(1)
else:
    n = len(arr) + 1
    s = sum(arr)
    print(abs(n * (n + 1) // 2 - s))
