def solve(s):
    weeks = {
        "thu hai": 2,
        "thu ba": 3,
        "thu tu": 4,
        "thu nam": 5,
        "thu sau": 6,
        "thu bay": 7,
        "chu nhat": 8
    }
    day = int(s[0: 2])
    t = s[len(str(day)) + 1::]
    d = (day - 1) % 7   
    print(list(weeks.keys())[list(weeks.values())[weeks[t] - d - 2] - 2])
for i in range(int(input())): solve(input())
