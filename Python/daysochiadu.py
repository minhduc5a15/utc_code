#! MLE
n, m, q = map(int, input().split())
arr = list(map(int, input().split()))
count = {}
for i in range(n):
    count[arr[i] % m].append(i + 1)
for _ in range(q):
    index, value = map(int, input().split())
    if value == m: value = 0
    if index > len(count[value]):
        print(-1)
    else:
        print(count[value][index - 1])