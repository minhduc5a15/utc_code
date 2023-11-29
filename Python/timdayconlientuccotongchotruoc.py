def solve(array, n: int, k: int):
    sum_pos, max_len, current_sum = {}, 0, 0
    for i in range(n):
        current_sum += array[i]
        if current_sum == k: max_len = i + 1
        if current_sum not in sum_pos: sum_pos[current_sum] = i
        if current_sum - k in sum_pos: max_len = max(max_len, i - sum_pos[current_sum - k])

    return max_len

n, k = map(int, input().split())
print(solve(list(map(int, input().split())), n, k))