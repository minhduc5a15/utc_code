def solve(t, arr):
    left, right = 1, max(arr) * t
    while left < right:
        mid = (left + right) // 2
        total = sum(mid // item for item in arr)
        if total >= t:
            right = mid
        else:
            left = mid + 1
    return left

n, t = map(int, input().split())
arr = list(map(int, input().split()))

print(solve(t, arr))
