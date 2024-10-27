n = float(input())
arr = [100, 50, 20, 10, 5, 2, 1, 0.50, 0.25, 0.10, 0.05, 0.01]
print("Tien giay: ")
for i in range(len(arr)):
    print(f"{int(n / arr[i]) } {'to' if i <= 5 else 'dong xu'} R$ {'{:.2f}'.format(arr[i])}")
    if arr[i] == 2:
        print("Tien xu:")
    n -= n - round(n % arr[i], 2)