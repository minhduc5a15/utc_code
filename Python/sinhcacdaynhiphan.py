def solve(n):
    if n == 0:
        return ['']
    smaller = solve(n - 1)
    return ['0' + bits for bits in smaller] + ['1' + bits for bits in smaller]

print('\n'.join(solve(int(input()))))
