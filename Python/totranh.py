def solve(n, actions):
    row = [0] * n
    col = [0] * n
    for action in actions:
        direction, index = action.split()
        index = int(index)
        if direction == 'H':
            row[index] = 1 - row[index]
        else:
            col[index] = 1 - col[index]
    return sum(row) * (n - sum(col)) + sum(col) * (n - sum(row))

print(solve(int(input()), [input() for _ in range(int(input()))]))
