MOD = 10**9 + 7
def solve(n: int):
    return (n * (n + 1) * (n + 2) // 6) % MOD
for _ in range(int(input())):
    print(solve(int(input())))