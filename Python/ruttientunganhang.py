m, n = map(int, input().split())
dp = [0 for _ in range(m + 1)]
dp[0] = 1
for num in list(map(int, input().split())):
    for i in range(num, m + 1):
        dp[i] += dp[i - num]
print(dp[-1])