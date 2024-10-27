arr = []
for i in range(20):
    arr.append(int(input()))
for i in range(19, -1, -1):
    print(f"N[{19 - i}] = ", arr[i])
