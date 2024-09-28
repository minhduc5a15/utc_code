def get_point(st: str):
    s = ""
    for char in st:
        if char.isdigit():
            s += char
    return int(s[0]), int(s[1])
def get_teams(st: str):
    first_team = ''
    second_team = ''
    for i in range(len(st)):
        if st[i].isdigit():
            pos_1 = i
            break
    for i in range(len(st)):
        if st[::-1][i].isdigit():
            pos_2 = i
            break
    for i in range(pos_1 - 1):
        first_team += st[i]
    for i in range(pos_2 - 1):
        second_team += st[::-1][i]
    return first_team, second_team[::-1]
n = int(input())
m = n * (n - 1) // 2
team = []
matches = []
for i in range(m):
    st = input()
    matches.append(st)
scores = {}
for match in matches:
    team1, team2, = get_teams(match)
    scores1, scores2 = get_point(match)
    if team1 not in scores:
        scores[team1] = 0
    if team2 not in scores:
        scores[team2] = 0
    if scores1 > scores2:
        scores[team1] += 3
    elif scores1 < scores2:
        scores[team2] += 3
    else:
        scores[team1] += 1
        scores[team2] += 1
for team, score in sorted(scores.items()):
    print(team, score)