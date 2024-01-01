def solve(s: str):
    return len(s) - s[::-1].find('1') - 1 if s[::-1].find('1') != -1 else -1

print(*[solve(input()) for _ in range(int(input()))], sep="\n")
