def max_number(n, k):
    stack = []
    removed = 0

    for current in n:
        while stack and removed < k and stack[-1] < current:
            stack.pop()
            removed += 1
        stack.append(current)
    while removed < k:
        stack.pop()
        removed += 1

    return ''.join(stack)
n, t = input(), int(input())
for i in range(t):
    print(max_number(n, int(input())))