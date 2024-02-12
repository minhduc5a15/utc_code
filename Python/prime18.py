def gcd(a: int, b: int) -> int:
    return a if b == 0 else gcd(b, a % b)

def lcm(a: int, b: int) -> int:
    return (a * b) // gcd(a, b)

def solve(n: int, a: int, b: int) -> int:
    s = n // a + n // b - n // lcm(a, b)
    return s

for _ in range(int(input())):
    m, n, a, b = map(int, input().split())
    print(solve(n, a, b) - solve(m - 1, a, b))
