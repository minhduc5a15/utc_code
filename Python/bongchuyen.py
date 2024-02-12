n = int(input())
arr = [0] * 6
action = ["Service", "Block", "Spike"]
for _ in range(n):
    player = input()
    arr_1 = list(map(int, input().split()))
    arr_2 = list(map(int, input().split()))
    arr[0] += arr_1[0]
    arr[1] += arr_2[0]
    arr[2] += arr_1[1]
    arr[3] += arr_2[1]
    arr[4] += arr_1[2]
    arr[5] += arr_2[2]
c = 0
for i in range(0, 6, 2):
    s = "{:.2f}%".format(round(arr[i + 1] * 100 / arr[i], 2))
    print(f"{action[c]}: {s.replace('.', ',')}.")
    c += 1
