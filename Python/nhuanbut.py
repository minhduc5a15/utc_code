n = int(input())
if type(n) is not int or n < 0:
    print("ERROR")
else:
    cent = n * 50
    dollar = int(n / 50) * 5
    print((cent // 100 + dollar) if cent % 100 == 0 else (cent / 100 + dollar))
