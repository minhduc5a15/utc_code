def solve(matrix):
    m = len(matrix)
    dp = [[0] * 3 for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(3):
            dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + matrix[i - 1][j]
    return max(dp[m])

print(solve([list(map(int, input().split())) for _ in range(int(input()))]))
