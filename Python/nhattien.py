n, m = map(int, input().split())
print(sum(sorted(list(map(int, input().split())), reverse=True)[0:m]))