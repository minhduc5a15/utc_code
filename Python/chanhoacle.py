def check(n: int) -> str:
    if n % 2 == 0 and n > 0:
        return "EVEN POSITIVE"
    elif n % 2 == 1 and n > 0:
        return "ODD POSITIVE"
    elif n % 2 == 0 and n < 0:
        return "EVEN NEGATIVE"
    elif n % 2 == 1 and n < 0:
        return "ODD NEGATIVE"
    elif n == 0:
        return "NULL"

n = int(input())
while True:
    attempt = input()
    try:
        num = [int(val) for val in attempt.split(" ")]
        if len(num) == n:
            break
        else:
            pass
    except:
        print("")

arr = list(map(int, num))
for item in arr:
    print(check(item))
