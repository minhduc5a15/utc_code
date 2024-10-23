from collections import Counter

n = int(input())
count = Counter(list(map(int, input().split())))
for item in count.items():
    if item[1] > n / 2:
        print(item[0])
        break
else: print("khong co phan tu ap dao")
