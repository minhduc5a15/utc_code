a, b, c = map(float, input().split())
d = b * b - 4 * a * c
if d < 0 or a == 0: print("Impossivel calcular")
else:
    x1 = (-b + d ** 0.5) / (2 * a)
    x2 = (-b - d ** 0.5) / (2 * a)
    print("R1 = {:.5f}".format(round(x1, 5)), "R2 = {:.5f}".format(round(x2, 5)), sep="\n")
