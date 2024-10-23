def solve(n, m):
    excessCash = m - n
    count = 0
    a = [100, 50, 20, 10, 5, 2]
    if excessCash >= 200:
        return 0
    if excessCash >= a[0]:
        excessCash -= a[0]
        count += 1
    for i in range(5):
        if a[i] > excessCash >= a[i + 1]:
            excessCash -= a[i + 1]
            count += 1
            if count > 2:
                return 0
    return count == 2

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    if solve(n, m):
        print("possible")
    else:
        print("impossible")
