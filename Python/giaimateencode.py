n = int(input())
s = input().lower()
arr = []
for _ in range(n):
    i = input()
    if i[0].lower() != s[0]:
        continue
    if ''.join([t[0] for t in i.split()]).lower() == s:
        arr.append(i)
print(len(arr))
print(*sorted(arr), sep='\n')
