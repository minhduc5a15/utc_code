def C2N(n: int):
    return n * (n - 1) // 2

def solve(arr: list, n: int):
    e_count = len([item for item in arr if item % 2 == 0])
    o_count = n - e_count
    return C2N(e_count) + C2N(o_count)

n = int(input())
arr = list(map(int, input().split()))
print(solve(arr, n))