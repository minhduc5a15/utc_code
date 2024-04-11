import math

def solve(H, a, b):
    H_prime = H - a
    D = math.ceil(H_prime / (a - b))
    return D + 1
a, b, H = map(int, input().split())
print(solve(H, a, b))