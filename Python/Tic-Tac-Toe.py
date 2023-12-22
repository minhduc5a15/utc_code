X, O = map(int, input().split())
check_pos = [1, 3, 7, 9]
if X in check_pos:
    if O != 5:
        print("X")
    else:
        print("D")
elif X == 5:
    if O in check_pos:
        print("D")
    else:
        print("X")
else:
    print("D")
