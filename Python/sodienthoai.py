print("YES" if len(num := input()) == 10 and num[len(num) - 1] not in ['4', '7', '0'] and num[0] == "0" else "NO")
