mod = 10**9 + 7
n = int(input())
s = 1
for i in range(1 if n % 2 == 0 else 2, n + 1, 2):
    s *= ((i % mod) * ((i + 1) % mod))
    s %= mod
if len(str(s)) >= 9: print(s)
else: print('0' * (9 - len(str(s))) + str(s))