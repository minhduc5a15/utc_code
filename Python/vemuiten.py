n = int(input())
for i in range(n, 0, -1):
    print((n * 2 - i * 2) * ' ' + '*' * i)
for i in range(2, n + 1):
    print((n * 2 - i * 2) * ' ' + '*' * i)
