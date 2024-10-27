arr = [num for num in [float(input()) for _ in range(6)] if num > 0]
print(f"{len(arr)} Gia tri duong", "{:.1f}".format(round(sum(arr) / len(arr), 1)) if len(arr) != 0 else "0.0", sep="\n")
