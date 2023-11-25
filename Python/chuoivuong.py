def gojo(s: str):
    return s[0:len(s) // 2] == s[len(s) // 2 : len(s)]

n = int(input())
arr = []
for i in range(n):
    str = input()
    arr.append(str)
for item in arr:
    print("YES" if gojo(item) else "NO")