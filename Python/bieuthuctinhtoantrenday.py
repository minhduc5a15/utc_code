n = int(input())
arr = list(map(int, input().split()))
s1, s2, s3 = 0, 0, 0
for i in range(n):
    s1 += arr[i] ** 2
    s2 += arr[i] * arr[n - i - 1]
    if i < n - 1:
        s3 += arr[i] * arr[i + 1]
print(s1, s2, s3, sep="\n")