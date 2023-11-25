import math

def scp(a):
    k = math.floor(a ** 0.5)
    if k*k == a: return True
    return False
def div(a):
    arr = []
    b = round(a ** 0.5)
    for i in range(1, b):
        if (a % i == 0):
            arr.extend([i, a // i])
    return sorted(arr, reverse=True)
def solve(num):
    if scp(num):
        print(f"1 {round(num ** 0.5)}")
    else:
        root, coe = 1, 1
    for item in div(num):
        if scp(item):
            coe = round(item ** 0.5)  
            root = num // item
            break      
    print(coe, root)
n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
for item in arr:
    solve(item)