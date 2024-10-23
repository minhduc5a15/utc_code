n = int(input())
n = 1000 - n
arr = [500, 100, 50, 10, 5, 1]
count = 0
for item in arr:
    count += n // item
    n -= n - n % item
print(count)