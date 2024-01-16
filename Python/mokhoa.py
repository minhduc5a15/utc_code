def min_steps(a, b):
    return min(abs(a - b), abs(a + 10 - b), abs(a - (b + 10)))

def solve(a, b):
    r = 0
    for i in range(len(a)):
        r += min_steps(int(a[i]), int(b[i]))
    print(r)
for _ in range(int(input())):
    input()
    solve(input(), input())
