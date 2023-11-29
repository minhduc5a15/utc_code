def check(s):
    return s.isalpha() and s.islower()

print("YES" if check(input()) else "NO")