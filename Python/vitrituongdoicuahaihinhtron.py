def solve(x1, y1, r1, x2, y2, r2):
    if x1 == x2 and y1 == y2 and r1 == r2:
        return "trung nhau"
    d = (x1 - x2) ** 2 + (y1 - y2) ** 2
    d = int(d ** 0.5) if int(d ** 0.5) ** 2 == d else d ** 0.5
    d1, d2 = abs(r1 - r2), r1 + r2
    if d <= d1:
        return "chua nhau"
    if d1 < d < d2:
        return "cat nhau"
    if d == d2:
        return "tiep xuc"
    return "roi nhau"
for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    print(solve(x1, y1, r1, x2, y2, r2))