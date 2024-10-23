def check_sequence(seq):
    if all(x < y for x, y in zip(seq, seq[1:])):
        return "TANG"

    if all(x > y for x, y in zip(seq, seq[1:])):
        return "GIAM"

    return "KHONGBIET"

arr = [int(x) for x in input().split()]
print(check_sequence(arr))
