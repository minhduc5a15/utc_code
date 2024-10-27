from collections import Counter

input()
counter = Counter(map(int, input().split()))
arr = [key for key in counter.keys()]
arr.sort(reverse=True)
print(f"1st: {counter.get(arr[0])}")
print(f"2nd: {counter.get(arr[1])}")
print(f"3rd: {counter.get(arr[2])}")