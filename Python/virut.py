def solve(n):
    count = 0
    res = 0
    while n > 3:
        res += n % 3
        n -= n % 3
        while n % 3 == 0:
            n //= 3
            count += 1
    return res + n
n = int(input())
print(*[solve(item) for item in list(map(int, input().split()))])
