a = int(input())
b = int(input())

print(sum(i if i & 1 else 0 for i in range(min(a, b) + 1, max(a, b))))
