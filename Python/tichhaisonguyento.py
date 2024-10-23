def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def check(n):
    if n <= 1:
        return False
    factors = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            if is_prime(i):
                factors.append(i)
            if is_prime(n // i):
                factors.append(n // i)
    factors = list(set(factors))
    if len(factors) == 2 and factors[0] * factors[1] == n:
        return True
    return False
print(str(check(int(input()))).lower())