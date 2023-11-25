def ucln(a: int, b: int) -> int:
    if a % b != 0:
        return ucln(b, a % b)
    else:
        return b

def bcnn(a: int, b: int) -> int:
    return (a * b) // ucln(a, b)

def result(n: int, a: int, b: int) -> int:
    s = n // a + n // b - n // bcnn(a, b)
    return s

for _ in range(int(input())):
    m, n, a, b = map(int, input().split())
    print(result(n, a, b) - result(m - 1, a, b))
    
