n, k = list(map(int, input().split()))
l = k
for i in range(1, n):
    l *= k - 1
print(l)