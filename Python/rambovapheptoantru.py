n, k = list(map(int, input().split()))
while k != 0:
    if n % 10 != 0: n -= 1
    else: n /= 10
    k -= 1
print(int(n))