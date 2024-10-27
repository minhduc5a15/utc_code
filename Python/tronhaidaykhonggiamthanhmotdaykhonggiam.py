input()
arr = list(map(int, input().split()))
input()
print(*sorted(arr + list(map(int, input().split()))))
