def solve(N):
    result = []
    for i in range(max(0, N - 9 * len(str(N))), N):
        if i + sum(int(digit) for digit in str(i)) == N:
            result.append(i)
    return result if result else [-1]

print(*solve(int(input())))
