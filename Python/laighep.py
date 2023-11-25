a = list(input())
b = list(input())
n = len(a)
c = [''] * n
res = []
for i in range(n):
	a[i], b[i] = b[i], a[i]

def solve(i: int):
	if i == n:
		res.append(''.join(c))
	else:
		c[i] = a[i]
		solve(i + 1)
		if b[i] != a[i]:
			c[i] = b[i]
			solve(i + 1)

solve(0)
print(*sorted(res), sep='\n')
