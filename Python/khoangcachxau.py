def check(s): return s[0] == s[-1]

s = input()
n = len(s)
i = 0
res = 0
while i < n:
    for j in range(n, i, -1):
        if check(s[i: j]):
            res = max(res, len(s[i: j]))
    i += 1
print(res)
