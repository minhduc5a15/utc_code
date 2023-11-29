# tuổi của bố và con
a, b, c = map(int, input().split())

print(int((c - 3 * b) / (3 * a - 1) * a + b), int((c - 3 * b) / (3 * a - 1)), sep='\n')