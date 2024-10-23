def solve(x, y):
    n = len(x)
    x = "#" + x
    m = len(y)
    y = "#" + y
    c = [[0 for _ in range(200)] for _ in range(200)]
    p = [[set() for _ in range(200)] for _ in range(200)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if x[i] == y[j]:
                c[i][j] = c[i - 1][j - 1] + 1
                if c[i][j] == 1:
                    p[i][j].add(x[i])
                else:
                    for s in p[i - 1][j - 1]:
                        p[i][j].add(s + x[i])
            else:
                c[i][j] = max(c[i - 1][j], c[i][j - 1])
                if c[i - 1][j] == c[i][j]:
                    for s in p[i - 1][j]:
                        p[i][j].add(s)
                if c[i][j - 1] == c[i][j]:
                    for s in p[i][j - 1]:
                        p[i][j].add(s)

    return p[n][m]

x = input()
y = input()
result = sorted(solve(x, y))
if result:
    for s in result:
        print(s)
else:
    print("khong co xau con chung")
