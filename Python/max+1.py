def solve(arr: list):
    max_n = arr[0]
    count = 0
    for i in range(1, len(arr)):
        if arr[i] <= max_n:
            arr[i] = max_n + 1
            count += 1
        max_n = arr[i]
    return count
input()
print(solve(list(map(int, input().split()))))