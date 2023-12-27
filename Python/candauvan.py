from math import gcd
def solve(n, a, b):
    g = gcd(a, b)
    if n % g != 0: return -1
    else:
        for i in range(n // b, -1, -1):
            if (n - b * i) % a == 0:
                return i + (n - b * i) // a
        return -1
n, a, b = map(int, input().split())
print(solve(n, a, b))
