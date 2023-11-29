MOD = 10 ** 9 + 7
def solve(n: int):
    r = n % 3
    if n == 1: return 1
    d = int(n / 3)
    if r == 1:
        d -= 1
        return (4 * pow(3, d, MOD)) % MOD
    if r == 0:
        return pow(3, d, MOD)
    if r == 2:
        return (2 * pow(3, d, MOD)) % MOD
print(solve(int(input())))
    