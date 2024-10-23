a, b = list(map(float, input().split()))
if a == b == 0:
    print("Vo So Nghiem")
elif a == 0 and b != 0:
    print("Vo Nghiem")
else:
    print("{:.3f}".format(round(-b / a, 3)))