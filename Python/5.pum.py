n, count = int(input()), 0


arr = [i for i in range(1, n * 3 + (n - 1) * 2, 4)]
for item in arr:
    count += 1
    if count == n + 1: break
    print(f"{item} {item + 1} {item + 2} Nam")