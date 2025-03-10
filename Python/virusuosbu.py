import math

n = int(input())
nums = list(map(int, input().split()))
g = nums[0]
for x in nums[1:]:
    g = math.gcd(g, x)
print(g)