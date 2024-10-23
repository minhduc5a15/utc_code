from itertools import permutations

def solve(n):
    perm = permutations(range(1, n + 1))
    return sorted(list(perm))

for item in solve(int(input())):
    print(''.join(map(str, item)))