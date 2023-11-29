from collections import Counter

def solve(arr: list):
    count = Counter(arr)
    result = [item for item in count.items()]
    result.sort(key = lambda x: x[1], reverse=True)
    max_times = result[0][1]
    count = [item[0] for item in result if item[1] == result[0][1]]
    print(max_times)
    print(*sorted(count))
input()
solve(list(map(int, input().split())))