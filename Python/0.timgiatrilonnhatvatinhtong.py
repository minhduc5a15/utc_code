n = int(input())
arr = list(map(int, input().split()))
s = 0
result = 0
for i in range(0, n):
    result = max(result, arr[i] / (n - i))
    s += arr[i]
if n == 1: print("{:.2f}".format(round(result, 2)), arr[0], sep='\n')
else: print("{:.2f}".format(round(result, 2)), 2 * s - arr[-1] - arr[0], sep='\n')
