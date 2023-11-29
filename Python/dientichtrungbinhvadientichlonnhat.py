x = int(input())
a = [0]*x
b = [0]*x
max_val = 0
c = 0

for i in range(x):
    a[i], b[i] = map(float, input().split())
    c += a[i]*b[i]
    if max_val < a[i]*b[i]:
        max_val = a[i]*b[i]

print("%.3lf" % (c/x))
print("%.3lf" % max_val)