def solve(n: int):
    if n == 0: return 1
    if n < 3: return n
    if n <= 4: return 6
    if n == 5: return 3
    if n > 5: return 9
for _ in range(int(input())):
    print(solve(int(input())))