def solve(x):
    if x <= 10: return x
    digit = []
    while x:
        digit.append(x % 10)
        x //= 10
    digit = digit[::-1]

    n = len(digit)

    dp = [[0] * n for _ in range(10)]
    check = [False] * n
    check[0] = True

    for i in range(1, n):
        check[i] = check[i - 1] and (digit[i] != digit[i - 1])
    for d in range(1, digit[0]):
        dp[d][0] = 1

    for i in range(1, n):
        if check[i - 1]:
            for d in range(digit[i]):
                if d != digit[i - 1]:
                    dp[d][i] += 1
        for d in range(1, 10):
            dp[d][i] += 1
        for d1 in range(10):
            for d2 in range(10):
                if d1 != d2:
                    dp[d2][i] += dp[d1][i - 1]

    res = check[n - 1]
    for d in range(10):
        res += dp[d][n - 1]
    return res

if __name__ == "__main__":
    a, b = map(int, input().split())
    print(solve(b) - solve(a - 1))

