from collections import Counter

def solve(arr: list):
    counter = Counter(arr)  
    
    sorted_item = sorted(counter.items(), key = lambda x: (-x[1], arr.index(x[0])))
    for i in range(min(3, len(sorted_item))):
        print(sorted_item[i][0], end=" ")
        
input()
solve(list(map(int, input().split())))