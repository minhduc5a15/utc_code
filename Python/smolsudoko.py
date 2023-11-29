def is_valid_sudoku(board):
    seen = set()
    for i in range(3):
        for j in range(3):
            number = board[i][j]
            if number in seen:
                return False
            if number < 1 or number > 9:
                return False
            seen.add(number)
    return True
arr = []
for i in range(3):
    item = [int(x) for x in input().split()]
    arr.append(item)
print("VALID" if is_valid_sudoku(arr) else "INVALID")