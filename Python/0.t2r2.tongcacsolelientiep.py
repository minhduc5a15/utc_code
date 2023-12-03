a = int(input())
b = int(input())

print(sum([i if i % 2 != 0 else 0 for i in range(min(a, b) + 1, max(a, b))]))

# code by duck it1
