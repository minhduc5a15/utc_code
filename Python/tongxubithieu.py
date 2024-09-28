def solve(arr):
    arr.sort()
    res = 1
    for num in arr:
        if num <= res:
            res += num
        else:
            break
    return res
input()
print(solve(list(map(int, input().split()))))
