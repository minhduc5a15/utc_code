def solve(h, m, s):
    t1 = 10
    t2 = 15
    total_time = t1 + t2
    sec = h * 3600 + m * 60 + s
    sec_since_on = sec - 18 * 3600
    if sec_since_on < 0:
        sec_since_on += 24 * 3600
    if sec_since_on >= total_time * ((12 * 3600) // total_time):
        return "OFF"
    current_cycle = sec_since_on % total_time
    if current_cycle < t1:
        return "ON"
    return "OFF"
h, m, s = map(int, input().split())
print(solve(h, m, s))