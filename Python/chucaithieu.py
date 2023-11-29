def missing_letters(s):
    alphabet = set('abcdefghijklmnopqrstuvwxyz')
    return ''.join(sorted(alphabet - set(s.lower())))

print(missing_letters(input()))
