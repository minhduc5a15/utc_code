def solve(s, arr):
    n = len(s)
    pos = []
    dict_arr = {arr[0][i]: i for i in range(len(arr[0]))}

    def backtrack(start, path):
        if start == n and ''.join(path) == s:
            pos.append([dict_arr[i] + 1 for i in path])
        for i in range(start, n):
            substring = s[start:i + 1]
            if substring in dict_arr:
                path.append(substring)
                backtrack(i + 1, path)
                path.pop()

    backtrack(0, [])
    result = []
    for x in pos:
        s = ''
        for i in x:
            s += arr[1][i - 1] + ' '
        result.append(s)
    return sorted(result) if result else ["Toto bo tay"]

arr = [[], []]
s = input()
for _ in range(int(input())):
    a, b = input().split()
    arr[0].append(a)
    arr[1].append(b)
print(*solve(s, arr), sep="\n")
