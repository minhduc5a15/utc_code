def get_info(s: str):
    arr = s.split()
    arr[0], arr[1] = int(arr[0]), float(arr[1])
    return arr


n = int(input())
arr = []
for i in range(n):
    s = input()
    arr.append(get_info(s))
count = 0
for item in arr:
    if item[0] % 3 == 0 and item[2] == 'B':
        count += 1
print(count)
arr.sort(key=lambda x: x[1])
for i in range(3):
    print(arr[i][0])
