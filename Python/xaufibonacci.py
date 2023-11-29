def find_char(n, k, fib):
    if n == 1:
        return 'A'
    if n == 2:
        return 'B'
    if k <= fib[n - 2]:
        return find_char(n - 2, k, fib)
    return find_char(n - 1, k - fib[n - 2], fib)

def solve(n, k):
    fib = [0] * 94
    fib[1] = fib[2] = 1
    for i in range(3, n + 1):
        fib[i] = fib[i - 1] + fib[i - 2]
    return find_char(n, k, fib)

for i in range(int(input())):
    n, k = map(int, input().split())
    print(solve(n, k))
