def solve(arr: list, n: int):
    pos = {}
    for i in range(n):
        pos[arr[i]] = i + 1
    result = [item for item in pos.items()]
    result.sort(key = lambda x: x[0])
    for pos in result:
        print(pos[1], end=" ")
n = int(input())
solve(list(map(int, input().split())), n)
