def power(x, y, p):
    res = 1
    x = x % p
    while (y > 0):
        if (y & 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def modInverse(n, p):
    return power(n, p - 2, p)

def solve(a, n):
    MOD = 10**9 + 7
    S = 1
    D = 1
    for i in range(1, n + 1):
        S = (S * (a + i)) % MOD
        D = (D * i) % MOD
    D_inv = modInverse(D, MOD)
    result = (S * D_inv) % MOD
    return result

a, n = map(int, input().split())
print(solve(a, n))