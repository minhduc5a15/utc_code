def solve(m, n, matrix):
    dp_count =[[0] * n for _ in range(m)]
    dp = [[float('inf')] * n for _ in range(m)]
    #first cell
    if matrix[0][0] > 0:
        dp[0][0] = matrix[0][0]
        dp_count[0][0] = 1
    #first row and column
    for i in range(1, m):
        if matrix[i][0] > 0:
            dp[i][0] = dp[i - 1][0] + matrix[i][0]
            dp_count[i][0] = 1
    for j in range(1, n):
        if matrix[0][j] > 0:
            dp[0][j] = dp[0][j - 1] + matrix[0][j]
            dp_count[0][j] = 1
    
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] > 0:
                if dp[i - 1][j] < dp[i][j - 1]:
                    dp[i][j] = dp[i - 1][j] + matrix[i][j]
                    dp_count[i][j] = dp_count[i - 1][j]
                elif dp[i - 1][j] > dp[i][j - 1]:
                    dp[i][j] = dp[i][j - 1] + matrix[i][j]
                    dp_count[i][j] = dp_count[i][j - 1]
                else:
                    dp[i][j] = dp[i - 1][j] + matrix[i][j]
                    dp_count[i][j] = dp_count[i - 1][j] + dp_count[i][j - 1]
    
    return (dp[-1][-1], dp_count[-1][-1]) if matrix[-1][-1] > 0 else (float("inf"), 0)

m, n = map(int, input().split())
matrix = []
for i in range(m):
    row = list(map(int, input().split()))
    matrix.append(row)
print(*solve(m, n, matrix))
