sinh = {
    "Kim": "Thuy",
    "Thuy": "Moc",
    "Moc": "Hoa",
    "Hoa": "Tho",
    "Tho": "Kim"
}
khac = {
    "Kim": "Moc",
    "Thuy": "Hoa",
    "Moc": "Tho",
    "Hoa": "Kim",
    "Tho": "Thuy"
}

a, b = input().split()
if sinh.get(a) == b:
    print(f"{a} sinh {b}")
elif sinh.get(b) == a:
    print(f"{b} sinh {a}")
elif khac.get(a) == b:
    print(f"{a} khac {b}")
elif khac.get(b) == a:
    print(f"{b} khac {a}")
