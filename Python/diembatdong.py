def solve(arr: list):
    count = len([i for i in range(len(arr)) if i == arr[i]])
    return count

input()
print(solve(list(map(int, input().split()))))