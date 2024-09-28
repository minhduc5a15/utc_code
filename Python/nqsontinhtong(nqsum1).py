n, x = map(int, input().split())
arr = list(map(int, input().split()))
for item in arr:
    if x - item in arr and item * 2 != x:
        print(*sorted([x - item, item]))
        break
