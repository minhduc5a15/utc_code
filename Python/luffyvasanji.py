def check() -> str:
    a, b = [int(i) for i in input().split()]
    c = round((a*b)**(1.0/3))
    return "YES" if (c ** 3 == a * b and a % c == 0 and b % c == 0) else "NO"
n = int(input())
while n > 0:
    n -= 1
    print(check())
    

        