def solve(arr: list):
    return sum(1 for i in range(len(arr)) if i == arr[i])

input()
print(solve(list(map(int, input().split()))))