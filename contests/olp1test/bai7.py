def convert(n):
    if n == 0:
        return '0'
    nums = []
    while n:
        n, r = divmod(n, 3)
        nums.append(str(r))
    return ''.join(nums[::-1])

def solve(n):
    n = n[::-1]
    res = 0
    for i in range(len(n)):
        res += 3 ** i * int(n[i])
    return res

x, y = map(int, input().split())
a = convert(x)
b = convert(y)
a = "0" * (len(b) - len(a)) + a
res = ""
for i in range(len(b)):
    tmp = int(b[i]) - int(a[i])
    while tmp < 0:
        tmp += 3
    res += str(tmp)