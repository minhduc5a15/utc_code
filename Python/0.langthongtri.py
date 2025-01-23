n = 0
graph = []
initial = []


def dfs(u, visited, v=None):
    if u == v:
        return
    visited[u] = True
    for i in range(n):
        if graph[u][i] and not visited[i]:
            dfs(i, visited, v)


def solve():
    global initial
    initial = [False] * n
    dfs(0, initial)
    result = []

    for i in range(n):
        visited = [False] * n
        if i != 0:
            dfs(0, visited, v=i)
        row = []
        for j in range(n):
            if initial[j] and (not visited[j] or i == j):
                row.append("Y")
            else:
                row.append("N")
        result.append(row)

    return result


def main():
    global n, graph
    t = int(input())
    for case in range(t):
        n = int(input())
        graph = [list(map(int, input().split())) for _ in range(n)]
        result = solve()
        print(f"Case {case + 1}:")
        print("+" + "-" * (2 * n - 1) + "+")
        for row in result:
            print("|" + "|".join(row) + "|")
            print("+" + "-" * (2 * n - 1) + "+")


if __name__ == "__main__":
    main()