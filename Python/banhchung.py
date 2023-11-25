input()
arr = [0] * 5
arr_input = list(map(int, input().split()))
for item in arr_input:
    arr[item] += 1
result = int(arr[2] / 2) + arr[4] + arr[3]
arr[1] -= arr[3]
if arr[2] % 2 != 0:
    result += 1
    arr[1] -= 2
print((result + int((arr[1] + 3) / 4)) if arr[1] > 0 else result) 