def solve(n: int, arr: list):
    return arr.count(n)

print(solve(int(input()), list(map(int, input().split()))))
