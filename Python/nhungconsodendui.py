from itertools import product

def get_the_missing_numbers(arr):
    a = []
    for i in range(10):
        if i not in arr:
            a.append(i)
    return a    
def solve(n, arr):
    arr.sort()
    for i in range(1, len(str(n)) + 2):
        for perm in product(arr, repeat=i):
            num = int(''.join(map(str, perm)))
            if num >= n:
                return num
n, k = map(int, input().split())
arr = get_the_missing_numbers(list(map(int, input().split())))
print(solve(n, arr))