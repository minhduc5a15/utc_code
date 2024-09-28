n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
sum_list = [a[i + n - 1] - a[i] for i in range(m - n + 1)]
min_value = min(sum_list)
print(min_value)
