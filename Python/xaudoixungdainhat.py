def manachers(s):
    s = '#'.join('^{}$'.format(s))
    n = len(s)
    p = [0] * n
    c = r = 0
    for i in range(1, n - 1):
        if r > i:
            p[i] = min(r - i, p[2 * c - i])
        while s[i + 1 + p[i]] == s[i - 1 - p[i]]:
            p[i] += 1
        if i + p[i] > r:
            c, r = i, i + p[i]
    max_len = max(p)
    return max_len
print(manachers(input()))


