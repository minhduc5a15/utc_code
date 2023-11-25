def find_max_dist(begin: int, end: int, arr: list):
    if begin >= arr[-1]:
        return 0
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] >= begin:
            element_l = arr[mid]
            right = mid - 1
        else:
            left = mid + 1
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] <= end:
            element_r = arr[mid]
            left = mid + 1
        else:
            right = mid - 1
    return element_r - element_l

# def hash_map(arr: list):
#     count = {}
#     for i in range(len(arr)):
#         if arr[i] not in count:
#             count[arr[i]] = []
#         count[arr[i]].append(i)
#     return count
def solve(arr: list, n: int, k: int):
    dictionary = {}
    result = []
    for i in range(k):
        if arr[i] not in dictionary:
            dictionary[arr[i]] = []
        dictionary[arr[i]].append(i)
    for i in range(k, n + 1):
        max_dist = 0


n, k = map(int, input().split())
arr = list(map(int, input().split()))
print(*solve(arr, n, k))
