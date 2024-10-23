import math

R = float(input()) 

if R < 0:
    print("NO CIRCLE")
else:
    circumference = 2 * math.pi * R
    area = math.pi * (R ** 2)
    print("{:.2f}".format(circumference))
    print("{:.2f}".format(area))