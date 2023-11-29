x = int(input())
i = int((x * 6) ** (1.0 / 3)) - 1
if x - i * (i + 1)*(i + 1) <= 0:
    print(i)
else:
    print(i + 1)