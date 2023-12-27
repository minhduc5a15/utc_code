def solve(n):
    def count_zeros(x):
        count = 0
        i = 5
        while x // i > 0:
            count += x // i
            i *= 5
        return count

    lower_bound = 0
    upper_bound = 5 * n

    while lower_bound < upper_bound:
        mid = (lower_bound + upper_bound) // 2
        count = count_zeros(mid)
        if count < n:
            lower_bound = mid + 1
        else:
            upper_bound = mid

    return lower_bound

for _ in range(1, 101):
    print(_, solve(_))