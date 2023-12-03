def is_leap_year(year):
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

def is_valid_date(day, month, year):
    if month < 1 or month > 12 or day < 1 or year < 1:
        return False

    if month in [1, 3, 5, 7, 8, 10, 12]:
        max_day = 31
    elif month == 2:
        if is_leap_year(year):
            max_day = 29
        else:
            max_day = 28
    else:
        max_day = 30

    return day <= max_day

day, month, year = map(int, input().split('/'))
if is_valid_date(day, month, year):
    print("Ngay hop le")
else:
    print("Ngay khong hop le")