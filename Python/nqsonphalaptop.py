n, x, y1, y2, z = map(int, input().split())
print(min(n * x, n * y1 + y2, z))