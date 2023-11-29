def solve(x, y, s):
    pens_to_buy = (s // (x + y)) * x
    if s % (x + y) > 0:
        pens_to_buy += min(s % (x + y), x)
    return pens_to_buy
x, y, s = map(int, input().split())
print(solve(x, y, s))