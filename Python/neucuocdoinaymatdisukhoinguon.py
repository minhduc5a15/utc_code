def solve(a, b):
    s = a + b
    num1 = int(''.join([char for char in str(a) if char != '0']))
    num2 = int(''.join([char for char in str(b) if char != '0']))
    num3 = int(''.join([char for char in str(s) if char != '0']))
    print("YES" if num1 + num2 == num3 else "NO")
a, b = map(int, input().split())
solve(a, b)