def leap_year(n):
    if n % 4 == 0:
        if n % 100 == 0:
            if n % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False
n = int(input())
if n < 2009: print(-1)
else: 
    print(f"{12 if leap_year(n) else 13}.09.{n} - Happy Programmer's Day!")
