def power(x, y, p):
    res = 1
    x = x % p
    while (y > 0):
        if (y & 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def solve(a, b):
    a = a % 1000
    if a == 0:
        return 0
    if b == 0:
        return 1
    phi = 400
    b = b % phi + phi
    return str(power(a, b, 1000)).zfill(3)

print(solve(int(input()), int(input())))
