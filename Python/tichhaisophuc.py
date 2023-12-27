def extract_number(s: str):
    num1 = num2 = ''
    pos = 0
    for i in range(len(s) - 1, 0, -1):
        if s[i] == '-' or s[i] == '+':
            pos = i
            break
    if pos == 0:
        if 'i' not in s:
            num1 = s
            num2 = '0'
        else:
            num2 = s[0: len(s) - 1]
            num1 = '0'
    else:
        for i in range(0, pos):
            num1 += s[i]
        if s[-1] == 'i':
            for i in range(pos, len(s) - 1):
                num2 += s[i]
        else:
            num2 = '0'
    if num2 == "+" or num2 == "-" or num2 == "": num2 += "1"
    return int(num1), int(num2)

def multiply_complex(a, b):
    real_part = a[0] * b[0] - a[1] * b[1]
    imaginary_part = a[0] * b[1] + a[1] * b[0]
    return real_part, imaginary_part

z1 = input()
z2 = input()
real_part, imaginary_part = multiply_complex(extract_number(z1), extract_number(z2))
if real_part == 0:
    if imaginary_part == 0:
        print(0)
    elif imaginary_part == 1:
        print("i")
    elif imaginary_part == -1:
        print("-i")
    else:
        print(f"{imaginary_part}i")
else:
    if imaginary_part == 0:
        print(real_part)
    elif imaginary_part == 1:
        print(f"{real_part}+i")
    elif imaginary_part == -1:
        print(f"{real_part}-i")
    elif imaginary_part > 1:
        print(f"{real_part}+{imaginary_part}i")
    else:
        print(f"{real_part}{imaginary_part}i")
