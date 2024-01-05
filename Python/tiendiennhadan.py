n = int(input())
print(n * 100 if n < 50 else n * 500 if 50 <= n < 1000 else n * 1000 if 1000 <= n < 10000 else n * 1200)
