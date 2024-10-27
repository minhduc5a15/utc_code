s1 = input()
s2 = input()
count = 0
for i in range(len(s1)):
    if s1[i] == s2[i]: count += 1
print(round((count/len(s1)) * 10, 1))
