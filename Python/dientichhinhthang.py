a, b = map(float, input().split())
print("{:.2f}".format(round((abs(a - b) / 2) * (a + b) / 2, 2)))
