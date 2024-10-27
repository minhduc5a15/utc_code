def cal(num):
    return (num-1)*num//2

a, b = map(int, input().split())

avg = a // b
r = a % b

res1 = b * cal(avg) + r * avg
res2 = cal(a - b + 1)

if a <= b:
    print("0 0")
else:
    print(res1, res2)