s = input()
n = len(s)
count = s.count('O')
curr, res = 0, 0
for i in range(n):
    if s[i] == 'O':
        curr += 1
    elif s[i] == 'A':
        res += curr * (count - curr)

print(res)