from collections import deque

def min_steps(n, m):
    if n < 0 or m < 0:
        return "ERROR"
    else:
        if n > m:
            return str(n - m)
        visited = [0] * (2*m + 1)
        queue = deque([(n, 0)])
        while queue:
            curr, steps = queue.popleft()
            if curr == m:
                return steps
            visited[curr] = 1
            if curr-1 >= 0 and not visited[curr-1]:
                queue.append((curr-1, steps+1))
            if curr*2 <= 2*m and not visited[curr*2]:
                queue.append((curr*2, steps+1))
        return "ERROR"
n, m = map(int, input().split())
print(min_steps(n, m))
