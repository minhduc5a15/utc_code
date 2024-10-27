arr = [int(x) for x in input().split()]
max_element = max(arr)
arr.remove(max_element)
print("Yes" if sum(arr) == max_element else "No")