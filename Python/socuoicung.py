def solve(a, b):
    if b == 0:
        return 1
    cycle = [a % 10]
    while True:
        next_digit = (cycle[-1] * a) % 10
        if next_digit == cycle[0]:
            break
        cycle.append(next_digit)

    return cycle[(b - 1) % len(cycle)]

a, b = map(int, input().split())
print(solve(a, b))
