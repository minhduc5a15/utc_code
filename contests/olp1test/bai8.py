def solve(n: int):
    if n == 0:
        return '0'
    nums = []
    while n:
        n, r = divmod(n, 3)
        nums.append(str(r))
    return ''.join(nums[::-1])
for _ in range(int(input())):
    print(solve(int(input())))