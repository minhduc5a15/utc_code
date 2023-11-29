def solve(name: str):
    name = name.lower()
    words = name.split()
    print("hello ", end="")
    for i in range(len(words) - 1):
        print(words[i][0], end='')
    print(words[-1])
for _ in range(int(input())): 
    solve(input())