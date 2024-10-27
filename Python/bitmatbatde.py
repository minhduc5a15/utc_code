def solve(n, k):
    if n == 1:
        return 1
    else:
        return (solve(n - 1, k) + k - 1) % n + 1

n, k = map(int, input().split())
print(solve(n, k))
