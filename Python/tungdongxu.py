def solve(s: str):
    arr = []
    i = 0
    while i < len(s):
        if len(s[i: i + 3]) == 3:
            arr.append(s[i: i + 3])
        i += 1
    count = {"SSS": 0, "SSN": 0, "SNS": 0, "SNN": 0, "NSS": 0, "NSN": 0, "NNS": 0, "NNN": 0}
    for item in arr:
        count[item] += 1
    for value in count.values():
        print(value, end=" ")

solve(input())