from bisect import bisect_left

def solve(arr):
    lis = []
    for num in arr:
        pos = bisect_left(lis, num)
        if pos == len(lis):
            lis.append(num)
        else:
            lis[pos] = num
    return len(lis)

input()
print(solve(list(map(int, input().split()))))
