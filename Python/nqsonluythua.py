def count(n, d):
    if n % d: return 0
    res = 0
    while n % d == 0:
        n //= d
        res += 1
    return res

def solve(arr: list, n: int):
    sum_arr = sum(arr)
    count_2 = 0
    count_5 = 0
    for i in range(n):
        r = sum_arr - arr[i]
        count_2 += count(arr[i], 2) * r
        count_5 += count(arr[i], 5) * r
    return min(count_2, count_5)
n = int(input())
print(solve(list(map(int, input().split()))))