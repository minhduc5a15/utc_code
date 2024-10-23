def count_numbers(list):
    positive_count = len([num for num in list if num > 0])
    negative_count = len([num for num in list if num < 0])
    return (positive_count, negative_count)
n = int(input())
arr = list(map(float, input().split()))
positive_count, negative_count = count_numbers(arr)
average = 0
square_root = 1
if negative_count != 0:
    for item in arr:
        if item < 0: average += item / negative_count
    print("{:.5f}".format(round(average, 5)))
else:
    print("khong co so am")
if positive_count != 0:
    for item in arr:
        if item > 0:
            square_root *= (item ** (1 / positive_count))
    print("{:.5f}".format(round(square_root, 5)))
else:
    print("khong co so duong")