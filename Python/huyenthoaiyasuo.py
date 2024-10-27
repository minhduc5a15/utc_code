n = int(input())
arr = list(map(int, input().split()))

count = 0
hasagi = 0
i = 0
k = -1
while i < len(arr):
    if arr[i] == 1:
        count += 1
    else:
        count = 0
    if count != 2:
        i += 1
    if count == 2:
        k = i
        i += 2
        hasagi += 1
        count = 0
print(hasagi if k != len(arr) - 1 else hasagi - 1)
