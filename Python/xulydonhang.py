from collections import defaultdict

mp = defaultdict()
n, m = map(int, input().split())
for _ in range(n):
    product, value = input().split()
    mp[product] = int(value)
res = 0
for _ in range(m):
    s = input()
    if s in mp: res += mp.get(s)
print(res)