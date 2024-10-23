s = input()
dict = {'SSS': 0, 'SSN': 0, 'SNS': 0, 'SNN': 0, 'NSS': 0, 'NSN': 0, 'NNS': 0, 'NNN': 0}
for i in range(len(s) - 2):
    dict[s[i:i + 3]] += 1
for value in dict.values():
    print(value, end=" ")
