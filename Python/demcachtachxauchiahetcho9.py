def solve(s):
    count = [0] * 10
    temp = 0
    for i in range(len(s)):
        temp = (temp + int(s[i])) % 9
        count[temp] += 1
    result = count[0]
    for i in range(9):
        result += int(count[i] * (count[i] - 1) / 2)
    return result % 1000000007

print(solve(input()))
