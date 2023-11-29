def solve(V):
    n = len(V)
    a = [0]*n
    a[0] = (V[0][1] + V[0][2] - V[1][2]) // 2
    for i in range(1, n):
        a[i] = V[0][i] - a[0]
    for i in range(n):
        for j in range(i+1, n):
            if i != j and a[i] + a[j] != V[i][j]:
                return [-1]
    return a

V = []
for _ in range(int(input())):
    item = list(map(int, input().split()))
    V.append(item)
print(*solve(V))