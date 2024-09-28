directions = {"B": 0, "DB": 1, "D": 2, "DN": 3, "N": 4, "TN": 5, "T": 6, "TB": 7}
start = directions.get(input())
start += sum(-1 if c == 'T' else 1 for c in input())
start %= 8
print(list(filter(lambda x: x[1] == start, directions.items()))[0][0])
