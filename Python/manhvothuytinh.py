def distance_point(x, y): return (x * x + y * y) ** 0.5

distance = max_distance = 0
for i in range(int(input())):
    x, y = map(float, input().split())
    distance += distance_point(x, y)
    max_distance = max(max_distance, distance_point(x, y))
print("{:.3f}".format(round(distance, 3)), "{:.3f}".format(round(max_distance, 3)), sep="\n")