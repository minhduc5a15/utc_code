from collections import deque

def is_valid(x, y, n, m):
    return 0 <= x < n and 0 <= y < m

def solve(n, m, x1, y1, x2, y2):
    dx = [-2, -1, 1, 2, 2, 1, -1, -2]
    dy = [1, 2, 2, 1, -1, -2, -2, -1]

    is_visited = [[False] * m for _ in range(n)]
    queue = deque([(x1, y1, 0)])
    is_visited[x1][y1] = True
    while queue:
        x, y, steps = queue.popleft()
        if x == x2 and y == y2:
            return steps
        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            if is_valid(nx, ny, n, m) and not is_visited[nx][ny]:
                queue.append((nx, ny, steps + 1))
                is_visited[nx][ny] = True
    return -1

n, m = map(int, input().split())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
print(solve(n, m, x1, y1, x2, y2))
