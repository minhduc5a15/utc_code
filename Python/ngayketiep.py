date_str = input("")
day, month, year = map(int, date_str.split("/"))

is_leap = year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)

days_in_month = [31, 29 if is_leap else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

day += 1
if day > days_in_month[month - 1]:
    day = 1
    month += 1
    if month > 12:
        month = 1
        year += 1

print("{}/{}/{}".format(day, month, year))
