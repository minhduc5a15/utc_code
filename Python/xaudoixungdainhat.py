def solve(s):
    n = len(s)
    dp = [[0 for _ in range(n)] for __ in range(n)]
    for i in range(1, n):
        l = 0
        for j in range(i, n):
            if s[l] == s[j]:
                dp[l][j] = dp[l + 1][j - 1]
            else:
                dp[l][j] = min(dp[l][j - 1], dp[l + 1][j]) + 1
            l += 1
    return dp[0][n - 1]

print(solve(input()))
