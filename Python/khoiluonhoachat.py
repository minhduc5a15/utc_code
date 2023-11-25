def solve(s):
    mass = {'H': 1, 'C': 12, 'O': 16}
    stack = []
    for char in s:
        if char.isalpha():
            stack.append(mass[char])
        elif char.isdigit():
            temp = stack.pop() * int(char)
            stack.append(temp)
        elif char == '(':
            stack.append(char)
        elif char == ')':
            temp = 0
            while stack[-1] != '(':
                temp += stack.pop()
            stack.pop()
            stack.append(temp)
        print(stack)
    return sum(stack)

print(solve("CH3((CHCOOH)2(CH2)8CO2H)3H2CO3H"))