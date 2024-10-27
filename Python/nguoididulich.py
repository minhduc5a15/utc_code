from itertools import permutations

def solve(graph):
    n = len(graph)
    vertices = list(range(n))
    paths = list(permutations(vertices))
    min_dist = float('inf')
    for path in paths:
        distance = 0
        for i in range(n - 1):
            distance += graph[path[i]][path[i+1]]
        distance += graph[path[-1]][path[0]] 
        min_dist = min(min_dist, distance)
    return min_dist

graph = []

for _ in range(int(input())):
    row = list(map(int, input().split()))
    graph.append(row)

print(solve(graph))
