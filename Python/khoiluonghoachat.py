MOD = 1e9 + 7
def solve(n):
    dp = [[[0, 0] for _ in range(3)] for _ in range(n + 1)]
    dp[1][0][0] = dp[1][1][0] = 1
    for i in range(2, n + 1):
        dp[i][0][0] = sum(dp[i - 1][j][0] for j in range(3)) % MOD
        dp[i][0][1] = sum(dp[i - 1][j][k] for j in range(3) for k in range(2)) % MOD
        
        dp[i][1][0] = dp[i - 1][0][0]
        dp[i][1][1] = dp[i - 1][0][0] + dp[i - 1][0][1]
        if i > 2:
            dp[i][2][0] = dp[i - 1][1][0]
            dp[i][2][1] = dp[i - 1][1][0] + dp[i - 1][1][1]
    return sum(dp[n][j][k] for j in range(3) for k in range(2)) % MOD
print(solve(8))