left_shoes = {}
right_shoes = {}
count = 0
shoes_list = [input() for _ in range(int(input()))]

for shoe in shoes_list:        
    direction, size = shoe[0], shoe[1:]
    if direction == 'L':
        if size in right_shoes and right_shoes[size] > 0:
            right_shoes[size] -= 1
            count += 1
        else:
            if size in left_shoes:
                left_shoes[size] += 1
            else:
                left_shoes[size] = 1
    else:
        if size in left_shoes and left_shoes[size] > 0:
            left_shoes[size] -= 1
            count += 1
        else:
            if size in right_shoes:
                right_shoes[size] += 1
            else:
                right_shoes[size] = 1
print(count)
