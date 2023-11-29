from math import gcd

num = int(input())
numerator, denominator = 1, 1
array = list(map(int, input().split()))
for i in range(0, num):
    if array[i] == 1:
        print("1/1")
        continue
    for value in range(2, array[i]+1):
        numerator = numerator*value + denominator
        denominator = denominator*value
    g = gcd(numerator, denominator)
    print(f"{numerator//g}/{denominator//g}")
    numerator, denominator = 1, 1
