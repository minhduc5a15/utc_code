def solve(a, b):
    a = a % 1000
    if a == 0:
        return 0
    if b == 0:
        return 1
    phi = 400
    b = b % phi + phi
    return str(pow(a, b, 1000)).zfill(3)

print(solve(int(input()), int(input())))
