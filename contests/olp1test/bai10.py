def check(a, b, c):
    if a + b <= c or a + c <= b or b + c <= a:
        return "KHONG PHAI TAM GIAC"
    else: return "TAM GIAC VUONG" if a * a + b * b == c * c else "TAM GIAC TU" if a * a + b * b < c * c else "TAM GIAC NHON" if a * a + b * b > c * c else ""
arr = list(map(float, input().split()))
arr.sort()
s = check(arr[0], arr[1], arr[2])
print(s)
if s != "KHONG PHAI TAM GIAC":
    if arr[0] == arr[1] == arr[2]:
        print("TAM GIAC DEU")
    elif arr[0] == arr[1] or arr[1] == arr[2]:
        print("TAM GIAC CAN")