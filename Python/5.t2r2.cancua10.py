def solve(n):
    result = 1.0 / 6
    if n == 0: return "3.0000000000"
    for _ in range(n - 1):
        result = 1.0 / (6 + result)
    return "{:.10f}".format(round(3 + result, 10))

n = int(input())
print(solve(n))