def check() -> str:
    a, b = map(int, input().split())
    c = round((a * b) ** (1 / 3))
    return "YES" if (c ** 3 == a * b and a % c == 0 and b % c == 0) else "NO"

for _ in range(int(input())):
    print(check())
