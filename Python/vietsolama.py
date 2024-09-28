def solve(n):
    result = ''
    while n >= 10:
        result += 'X'
        n -= 10
    if n >= 5:
        result += 'V'
        n -= 5
    while n > 0:
        result += 'I'
        n -= 1
    return result

print(solve(int(input())))
