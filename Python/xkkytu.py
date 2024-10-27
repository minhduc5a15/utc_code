def solve(s: str, k: int):
    for char in s: print(char * k, end='')
    print()
for _ in range(int(input())):
    a, b = map(int, input().split())
    solve(b, a)
