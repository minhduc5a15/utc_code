import math

n = int(input())
x0, h = map(float, input().split())
y_values = list(map(float, input().split()))
q = int(input())
x_points = [float(input()) for _ in range(q)]

delta_y = [y_values]
for i in range(1, n + 1):
    delta_y.append([delta_y[i - 1][j + 1] - delta_y[i - 1][j] for j in range(len(delta_y[i - 1]) - 1)])

for x in x_points:
    u = (x - x0) / h
    result = delta_y[0][0]
    p = 1
    for i in range(1, n + 1):
        p *= (u - (i - 1))
        result += (p * delta_y[i][0]) / math.factorial(i)
    print(f"{result:.3f}")
