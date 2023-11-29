def upper_factorial(x, n):
    result = 1
    for i in range(n):
        result *= (x + i)
    return result
n, k = list(map(int, input().split()))
r = n % k
first_num = r
result = 1
if first_num == 0: first_num += k
count = int((n - first_num) / k) + 1
print(round(k ** count * (upper_factorial(first_num / k, count))))