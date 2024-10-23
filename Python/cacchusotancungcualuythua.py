M = pow(10, 101)
a = input()
b = input()
l = int(input())
a = int(a[-l - 1:])
b = int(b[-l - 1:])
c = (str(pow(a, b, M))).rjust(l, 'X')[-l:]
if c[-1:] == "0":
    print("0" * l)
else:
    print(c)
