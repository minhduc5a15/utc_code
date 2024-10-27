h, m, s = map(int, input().split())
if h <= 6: h += 24
a = (h - 18) * 3600
b = m * 60
c = a + b + s
if h != 30 and c % 25 < 11:
    print('ON')
else:
    print('OFF')
