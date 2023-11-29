def solve(arr: list):
    n = len(arr)
    max_len, m = 0, 0
    pos = {}
    for i in range(n):
        if arr[i] in pos:
            m = max(m, pos[arr[i]] + 1)
        pos[arr[i]] = i
        max_len = max(max_len, i - m + 1)
    return max_len
input()
arr = list(map(int, input().split()))
print(solve(arr))