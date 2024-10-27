import math

a, b, c = map(float, input().split())
if a == 0:
    if b == 0:
        if c == 0:
            print("vo so nghiem")
        else:
            print("vo nghiem")
    else:
        print(f"{-c / b:.3f}")
else:
    d = b * b - 4 * a * c
    if d < 0:
        print("vo nghiem")
    elif d == 0:
        print(f"{-b / (2 * a):.3f}")
    else:
        x1 = (-b + math.sqrt(d)) / (2 * a)
        x2 = (-b - math.sqrt(d)) / (2 * a)
        if x1 < x2:
            print(f"{x1:.3f}\n{x2:.3f}")
        else:
            print(f"{x2:.3f}\n{x1:.3f}")
