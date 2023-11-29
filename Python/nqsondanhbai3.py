from math import log2
def m(n):
    return int(log2(n))
n = int(input())
print(2 * (n - 2 ** m(n)) + 1)