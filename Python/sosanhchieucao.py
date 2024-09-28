def compare(x, y):
    if x > y:
        return "cao hon"
    elif x < y:
        return "thap hon"
    elif x == y:
        return "bang nhau"

a = list(map(str, input().split()))
b = list(map(str, input().split()))
if compare(a[1], b[1]) == "cao hon":
    print(f"{a[0]} cao hon {b[0]}")
elif compare(a[1], b[1]) == "thap hon":
    print(f"{b[0]} cao hon {a[0]}")
elif compare(a[1], b[1]) == "bang nhau":
    print(f"{a[0]} cao bang {b[0]}")
