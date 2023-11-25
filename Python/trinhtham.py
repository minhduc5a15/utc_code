from collections import deque
def solve(arr, n, k):
    Qi = deque()
    for i in range(k):
        while Qi and arr[i] >= arr[Qi[-1]]:
            Qi.pop()
        Qi.append(i)
    for i in range(k, n):
        print(str(arr[Qi[0]]), end=" ")
        while Qi and Qi[0] <= i-k:
            Qi.popleft()
        while Qi and arr[i] >= arr[Qi[-1]]:
            Qi.pop()
        Qi.append(i)
    print(arr[Qi[0]])

n, k = map(int, input().split())
arr = list(map(int, input().split()))
solve(arr, n, k)
