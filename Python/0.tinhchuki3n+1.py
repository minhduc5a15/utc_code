def solve(n: int):
    arr = []
    count = 1
    while n != 1:
        count += 1
        arr.append(n)
        if n & 1:
            n = 3 * n + 1
        else:
            n //= 2
    arr.append(1)
    print(count, *arr)
solve(int(input()))