def max_number(n, k):
    stack = []
    removed = 0

    for current in n:
        while stack and removed < k and stack[-1] < current:
            print(stack)
            stack.pop()
            removed += 1
        stack.append(current)
    while removed < k:
        stack.pop()
        removed += 1

    return ''.join(stack)
# n, t = input(), int(input())
# for i in range(t):
#     print(max_number(n, int(input())))
print("6345423410035456542234234")
max_number("6345423410035456542234234", 5)