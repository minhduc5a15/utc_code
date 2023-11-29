def kadane(arr: list, n):
    max_so_far, max_ending_here = arr[0], arr[0]
    for i in range(1, n):
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far 
n = int(input())
print(kadane(list(map(int, input().split())), n))