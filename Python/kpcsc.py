import math
def diffArr(arr):
    list = []
    for i in range(len(arr) - 1):
        list.append(abs(arr[i+1] - arr[i]))
    return list



arr = [int(x) for x in input().split()]

gcdList = 0
count = 0
for i in range(0, len(diffArr(arr))):
    gcdList = math.gcd(gcdList, diffArr(arr)[i])
for i in range(len(diffArr(arr))):
    count += diffArr(arr)[i] // gcdList - 1
print(count)
