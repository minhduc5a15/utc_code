from math import factorial

n = int(input())
print(factorial(n) // (factorial(n - 3) * 6) if n >= 3 else 0)
