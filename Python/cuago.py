def solve(L, l):
    d = (L // l - 1) * (l + 1) 
    if L % l == 0: return d
    return d + L % l + 1
L, l = map(int, input().split())
print(solve(L, l))