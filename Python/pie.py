# i don't know where the bug is :<

from math import pi

PI = pi
def check(mid, radii, F):
    pieces = sum(int(PI * r * r / mid) for r in radii)
    return pieces >= F

def max_piece_size(radii, F):
    left, right = 0, PI * max(radii) ** 2
    while right - left > 1e-5:
        mid = (left + right) / 2
        if check(mid, radii, F):
            left = mid
        else:
            right = mid
    return left

for i in range(int(input())):
    n, f = map(int, input().split())
    pies_radii_list = list(map(int, input().split()))
    print("{:.3f}".format(round(max_piece_size(list(map(int, input().split())), f + 1), 3)))