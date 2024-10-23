def solve(s):
    if s == "":
        return [""]
    
    dp = [[] for _ in range(len(s) + 1)]
    dp[0] = ['']
    
    for i in range(1, len(s) + 1):
        if int(s[i - 1: i]) > 0: 
            dp[i] += [result + chr(int(s[i - 1: i]) + ord('a') - 1) for result in dp[i - 1]]
        if i != 1 and 10 <= int(s[i-2:i]) <= 26:
            dp[i] += [result + chr(int(s[i - 2:i]) + ord('a') - 1) for result in dp[i - 2]]
    
    return dp[len(s)]

print(*solve(input()), sep="\n")
