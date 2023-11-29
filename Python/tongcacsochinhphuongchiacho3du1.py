from math import comb, isqrt

MOD = 10**9 + 7

def cal(n: int):
    return comb(n + 1, 3) + comb(n + 2, 3)
def solve(n: int):
    sqrt_n = isqrt(n)
    return (cal(sqrt_n) % MOD - (9 * cal(int(sqrt_n / 3)) % MOD + MOD)) % MOD
for _ in range(int(input())):
    print(solve(int(input())))