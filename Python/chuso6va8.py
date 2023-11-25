from collections import deque

def solve(n: int):
    if n % 10 == 0 or n % 10 == 5: return 0
    queue = deque(['6'])
    while queue:
        num = queue.popleft()
        if int(num) % n == 0:
            return num
        queue.append(num + '6')
        queue.append(num + '8')

result = solve(int(input()))
print(result)
