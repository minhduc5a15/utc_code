def solve(arr, k):
    current_sum = arr[0]
    result = [arr[0]]
    for i in range(1, len(arr)):
        current_sum += arr[i]
        result.append(current_sum)
    return result[k - 1]
n, m = map(int, input().split())
arr = list(map(int, input().split()))
input()
queries = list(map(int, input().split()))
for item in queries:
    print(m + solve(arr, item))
