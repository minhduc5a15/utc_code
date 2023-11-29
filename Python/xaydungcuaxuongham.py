def solve(arr):
    arr.sort()
    return sum(abs(s - arr[len(arr) // 2]) for s in arr)

input()
print(solve(list(map(int, input().split()))))