dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

def is_valid(x, y, n, m):
    return 0 <= x < n and 0 <= y < m

def dfs(x, y, n, m):
    visited[x][y] = True
    area = 1
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if is_valid(nx, ny, n, m) and not visited[nx][ny] and image[nx][ny] == 0:
            area += dfs(nx, ny, n, m)
    return area

n, m = map(int, input().split())
image = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]
areas = []

for i in range(n):
    for j in range(m):
        if image[i][j] == 0 and not visited[i][j]:
            areas.append(dfs(i, j, n, m))

print(len(areas))
print(*sorted(areas))
