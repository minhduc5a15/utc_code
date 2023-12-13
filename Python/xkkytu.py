def solve(s: str, k: int):
    for char in s: print(char * k, end='')
    print()
for _ in range(int(input())):
    arr = list(map(str, input().split()))
    solve(arr[1], int(arr[0]))
