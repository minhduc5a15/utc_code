def find_min_diff(arr):
    min_diff = float("inf")
    for k in range(min(arr), max(arr) + 1):
        diff_sum = sum((num - k) ** 2 for num in arr)
        min_diff = min(min_diff, diff_sum)
    return min_diff

n = int(input())
arr = list(map(int, input().split()))
min_k = find_min_diff(arr)
print(min_k)
