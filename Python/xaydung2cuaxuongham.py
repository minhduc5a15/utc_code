n = int(input())
arr = [0] + sorted(map(int, input().split()))
prefix_sum = [0] * (n + 1)
for i in range(1, n + 1):
    prefix_sum[i] = prefix_sum[i - 1] + arr[i]

def calc(left, right):
    mid = (left + right) // 2
    return prefix_sum[right] - 2 * prefix_sum[mid] + prefix_sum[left - 1] + arr[mid] * (2 * mid + 1 - right - left)

res = float('inf')
for i in range(1, n):
    res = min(res, calc(1, i) + calc(i + 1, n))

print(res)
