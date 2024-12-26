from itertools import accumulate

n = int(input())
arr = list(map(int, input().split()))
prefix = [0] + list(accumulate(arr))
dp = [[float('inf')] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = 0

for length in range(2, n + 1):
    for i in range(n - length + 1):
        j = i + length - 1
        s = prefix[j + 1] - prefix[i]
        dp[i][j] = min(dp[i][k] + dp[k + 1][j] + s for k in range(i, j))

print(dp[0][-1])
