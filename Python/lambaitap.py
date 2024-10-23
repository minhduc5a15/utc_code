a, b, c, d = map(int, input().strip().split(" "))

print(0 if max(a, c) > min(b, d) else min(b, d) - max(a, c))
