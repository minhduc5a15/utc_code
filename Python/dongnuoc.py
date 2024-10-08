from collections import deque
from math import gcd

def BFS(a, b, target):
    visited = [[False, False] for _ in range(b + 1)]
    q = deque()
    q.append([0, 0])
    while q:
        u = q.popleft()
        if u[0] > a or u[1] > b or u[0] < 0 or u[1] < 0:
            continue
        if visited[u[0]][u[1]]:
            continue
        visited[u[0]][u[1]] = True
        if u[0] == target or u[1] == target:
            return True
        q.append([u[0], b])
        q.append([a, u[1]])
        for pour in range(0, max(a, b) + 1):
            c = u[0] + pour
            d = u[1] - pour
            if c == a or (d == 0 and d >= 0):
                q.append([c, d])
            c = u[0] - pour
            d = u[1] + pour
            if (c == 0 and c >= 0) or d == b:
                q.append([c, d])
        q.append([a, 0])
        q.append([0, b])
    return False

def pour(fromCap, toCap, c):
    from_ = fromCap
    to = 0
    step = 1
    while from_ != c and to != c:
        temp = min(from_, toCap - to)
        to += temp
        from_ -= temp
        step += 1
        if from_ == c or to == c:
            break
        if from_ == 0:
            from_ = fromCap
            step += 1
        if to == toCap:
            to = 0
            step += 1
    return step

def solve(a, b, c):
    if a > b:
        a, b = b, a
    if c > b or c % gcd(a, b) != 0:
        return "Khong dong duoc nuoc"
    return min(pour(a, b, c), pour(b, a, c))

a, b, c = map(int, input().split())
print(solve(a, b, c))
