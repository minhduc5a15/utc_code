s = input()
text = ""
for char in s:
    if char == '0' or char == '1':
        text += char
    else: 
        if (len(text) > 0):
            text = text[0:len(text)-1]
print(text)