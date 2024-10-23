for __ in range(int(input())):
    arr = []
    for _ in range(int(input())):
        y, x = map(int, input().split())
        arr.append((x, y))
    arr.sort(key=lambda x: x[0])
    count, d1, d2 = 0, 0, 0
    for x, y in arr:
        if d1 < d2: d1, d2 = d2, d1
        if y > d1:
            count += 1
            d1 = x
        elif y > d2:
            count += 1
            d2 = x
    print(count)