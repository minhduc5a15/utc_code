def solve(s):
    stack = []
    for char in s:
        while stack and stack[-1] == char:
            stack.pop()
        stack.append(char)
    return ''.join(stack)

input()
print(solve(input()))
