from math import gcd

input()
arr = list(map(int, input().split()))
g = arr[0]
for i in arr: g = gcd(g, i)
print(g)