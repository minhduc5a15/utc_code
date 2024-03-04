from collections import deque

def solve(n, k, m, s, f):
    visited = [False] * (n+1)
    queue = deque([(s, 0)])

    while queue:
        current_floor, steps = queue.popleft()
        if current_floor == f:
            return steps

        next_floors = [current_floor - m, current_floor + k]
        for next_floor in next_floors:
            if 1 <= next_floor <= n and not visited[next_floor]:
                visited[next_floor] = True
                queue.append((next_floor, steps + 1))

    return -1

n = int(input())
k, m = map(int, input().split())
s, f = map(int, input().split())
print(solve(n, k, m, s, f))