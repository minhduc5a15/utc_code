def solve(n: int):
    min_len = len(str(n))
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0: 
            min_len = min(max(len(str(i)), len(str(int(n / i)))), min_len)
    return min_len
print(solve(int(input())))