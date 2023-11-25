import heapq
from collections import Counter

def solve(s):
    arr = Counter(s)
    heap = [[weight, [char, ""]] for char, weight in arr.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for pair in lo[1:]:
            pair[1] = "0" + pair[1]
        for pair in hi[1:]:
            pair[1] = "1" + pair[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])

    huffman_code = sorted(heapq.heappop(heap)[1:], key=lambda p: (len(p[-1]), p))
    result = sum(arr[char] * len(code) for char, code in huffman_code)

    return result


print(solve(input()))
