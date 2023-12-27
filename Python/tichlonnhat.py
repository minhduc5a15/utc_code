def solve(n: int):
    count = int(n / 3)
    if n % 3 == 1:
        return (3 ** (count - 1)) * 4
    elif n % 3 == 2:
        return (3 ** count) * 2
    else:
        return 3 ** count

for i in range(int(input())):
    print(solve(int(input())))
