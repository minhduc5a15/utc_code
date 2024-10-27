n = int(input())
arr = [0] + list(map(int, input().split()))

pos = [(num, i) for i, num in enumerate(arr)]
pos.sort()
arr.append(0)
res = 0
for i in range(1, n + 1):
    if arr[pos[i][1]] == 0: continue
    arr[pos[i][1] - 1] = 0
    arr[pos[i][1] + 1] = 0
    res += 1

print(res)