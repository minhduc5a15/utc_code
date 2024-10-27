def prime_number(n):
    if n <= 1:
        return False
    else:
        for i in range(2, round(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True
print("YES" if prime_number(int(input())) else "NO")