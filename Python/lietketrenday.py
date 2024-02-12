def solve(arr: list):
    arr_1 = [item for item in arr if item & 1]
    arr_2 = [item for item in arr if item % 5 == 2 or item % 7 == 3]
    arr_3 = [[arr[i - 1], arr[i], arr[i + 1]] for i in range(1, len(arr) - 1) if arr[i] - arr[i - 1] == arr[i + 1] - arr[i]]
    if arr_1: print(*arr_1)
    else: print("Day khong co so le")
    if arr_2: print(*arr_2)
    else: print("Day khong co so chia nam du hai hoac chia bay du ba")
    if arr_3:
        for item in arr_3:
            print(*item)
    else:
        print("Day khong co bo ba lien tiep cap so cong")
input()
solve(list(map(int, input().split())))
