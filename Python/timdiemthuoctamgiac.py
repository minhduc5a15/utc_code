def dist(a, b, c, d):
    return ((a - c) ** 2 + (b - d) ** 2) ** 0.5

arr = []
for i in range(4):
    a, b = map(int, input().split())
    arr.append([a, b])
max_distance = 0
pos = 0
for i in range(3):
    if dist(arr[i][0], arr[i][1], arr[3][0], arr[3][1]) > max_distance:
        pos = i
        max_distance = dist(arr[i][0], arr[i][1], arr[3][0], arr[3][1])
print(*arr[pos])
