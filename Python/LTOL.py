def solve(n : int) -> str:
    if (n % 16 == 0): return "LTOL"
    elif (n % 8 == 0): return "LTO"
    elif (n % 4 == 0): return "LT"
    elif (n % 2 == 0): return "L"
    
for i in range(1, int(input()) + 1):
    print(i if i % 2 != 0 else solve(i))

