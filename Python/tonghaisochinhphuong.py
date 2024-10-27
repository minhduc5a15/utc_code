import math

def solve(n):
    s = set()
    for a in range(int(math.sqrt(n)) + 1):
        bb = n - a * a
        b = int(math.sqrt(bb))
        if b * b == bb:
            s.add(tuple(sorted((a, b))))
    return len(s)

print(solve(int(input())))
