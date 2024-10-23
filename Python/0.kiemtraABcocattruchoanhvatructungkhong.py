def solve(x1, y1, x2, y2):
    if (x1 * x2 < 0) and (y1 * y2 < 0):
        return "YES"
    else:
        return "NO"
a, b, c, d = map(float, input().split())
print(solve(a, b, c, d))
