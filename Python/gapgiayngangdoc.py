def solve(n):
    if (n & (n - 1)) == 0:
        folds = int(n.bit_length() - 1)
        return 2 ** folds
    else:
        return 0

print(solve(int(input())))
