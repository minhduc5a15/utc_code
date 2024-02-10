n, w, t = map(int, input().split())
arr = list(map(int, input().split()))
current_w = 0
res = 0
for i in range(t):
    current_w += arr[i]
if current_w < w:
    res += w - current_w
    current_w = w
    arr[t - 1] += res
for i in range(1, n - t + 1):
    current_w -= arr[i - 1]
    current_w += arr[t + i - 1]
    if current_w < w:
        res += w - current_w
        arr[t + i - 1] += w - current_w
        current_w = w

print(res)