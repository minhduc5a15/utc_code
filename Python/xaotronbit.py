while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0:
        break
    binary = f"{n:032b}"
    max_n, min_n = n, n
    for _ in range(k):
        a, b = map(int, input().split())
        bin_list = list(binary)
        bin_list[31 - a], bin_list[31 - b] = bin_list[31 - b], bin_list[31 - a]
        binary = ''.join(bin_list)
        res = int(binary, 2)
        max_n = max_n(max_n, res)
        min_n = min(min_n, res)

    print(res, max_n, min_n)
