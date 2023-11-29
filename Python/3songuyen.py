arr = list(map(int, input().split()))

arr1 = [arr[0], arr[1], max(arr) - (arr[0] + arr[1])]
arr3 = [arr1[0], arr1[1], max(arr) - (arr[0] + arr[1]), arr1[0] + arr1[1], arr1[0] + arr1[2], arr1[1] + arr1[2], sum(arr1)]
if sorted(arr3) == arr:
    print(*arr1)
else:
    print(-1)