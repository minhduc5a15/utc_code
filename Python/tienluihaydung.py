for _ in range(int(input())):
    a, b, c = map(int, input().split())
    if a < b: print("TIEN", "TIEN" if c > b else "LUI" if c < b else "DUNG")
    elif a > b: print("LUI", "TIEN" if c > b else "LUI" if c < b else "DUNG")
    else: print("DUNG", "TIEN" if c > b else "LUI" if c < b else "DUNG")