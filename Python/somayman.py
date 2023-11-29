from itertools import product
LIMIT = 999999999
def solve(n: int):
    lucky_nums = [''.join(p) for i in range(1, 10) for p in product('2015', repeat=i)]
    lucky_nums = [int(num) for num in lucky_nums if int(num) % n == 0 and 0 < int(num) <= LIMIT]
    return sorted(list(set(lucky_nums)))
print(*solve(int(input())), sep='\n')