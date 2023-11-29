def row(start, amount):
    count = 0
    arr = []
    while count < amount:
        arr.append(start)
        start *= 2
        count += 1
    return arr
def solve(n):
    arr = []
    for i in range(0, n):
        arr.append(row(2 ** i, n))
    for item in arr:
        print(*item, '\n')
n = int(input())
while n != 0:
    solve(n)
    n = int(input())