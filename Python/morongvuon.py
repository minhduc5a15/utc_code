s, n, t = map(int, input().split())
m = int((t - n * n) / n)
c_dai = int((m + (m * m - 4 * s) ** 0.5) / 2)
c_rong = s // c_dai
print(c_dai, c_rong)