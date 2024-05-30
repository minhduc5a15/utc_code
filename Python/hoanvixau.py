def count_letter(s):
    counts = [0] * 26
    result = []
    for char in s:
        if 'a' <= char <= 'z':
            counts[ord(char) - ord('a')] += 1
    for i, count in enumerate(counts):
        result.append([chr(ord('a') + i), count])
    return result
def check(a: str, b: str) -> bool:
    count_letter_a = count_letter(a)
    count_letter_b = count_letter(b)
    for i, count in enumerate(count_letter_b):
        if count[1] > count_letter_a[i][1]:
            return False
    return True
a = input()
b = input()
print("yes" if check(a, b) else "no")