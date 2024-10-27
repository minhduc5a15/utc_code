from math import gcd

def solve(a, b):
    a2 = a3 = a5 = b2 = b3 = b5 = 0
    c = gcd(a, b)
    a //= c
    b //= c
    while a % 2 == 0: 
        a //= 2
        a2 += 1
    while a % 3 == 0: 
        a //= 3
        a3 += 1
    while a % 5 == 0: 
        a //= 5
        a5 += 1
    while b % 2 == 0: 
        b //= 2
        b2 += 1
    while b % 3 == 0: 
        b //= 3
        b3 += 1
    while b % 5 == 0: 
        b //= 5
        b5 += 1

    if a != 1 or b != 1:
        return -1
    else:
        return abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5)
a, b = map(int, input().split())
print(solve(a, b))