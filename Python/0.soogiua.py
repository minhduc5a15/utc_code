arr = list(map(int, input().split()))
print("KHONG CO SO O GIUA" if len(list(set(arr))) != len(arr) else sorted(arr)[1])
