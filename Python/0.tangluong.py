def solve(n):
    if 0 <= n <= 400: return 15
    elif 400 < n <= 800: return 12
    elif 800 < n <= 1200: return 10
    elif 1200 < n <= 2000: return 7
    elif n > 2000: return 4
n = float(input())
l = "{:.2f}".format(round(n + n * solve(n) / 100, 2))
t = "{:.2f}".format(round(n * solve(n) / 100, 2))
p = f"{solve(n)}%"
print(f"Luong: {l} ")
print(f"Tien kiem duoc: {t}")
print(f"Ty le phan tram: {p}")