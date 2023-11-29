from itertools import permutations

def solve(s):
    if len(set(s)) == 1:
        return [s]
    else:
        perms = [''.join(p) for p in permutations(s)]
        unique_perms = list(set(perms))
        unique_perms.sort()
        return unique_perms

for item in solve(input()):
    print(item)