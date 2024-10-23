n, d = map(int, input().split())
dp = [0] + [float('inf')] * (n - 1)
s = input()
for i in range(1, n):
    if s[i] == '1':
        for j in range(max(0, i - d), i):
            dp[i] = min(dp[i], dp[j] + 1)
print(-1 if dp[-1] == float('inf') else dp[-1])
