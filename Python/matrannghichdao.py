def get_minor(matrix, row, col):
    return [[matrix[i][j] for j in range(len(matrix[i])) if j != col] for i in range(len(matrix)) if i != row]

def get_determinant(matrix):
    if len(matrix) == 2: return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    return sum(((-1) ** c) * matrix[0][c] * get_determinant(get_minor(matrix, 0, c)) for c in range(len(matrix)))

def inverse(matrix):
    determinant = get_determinant(matrix)
    n = len(matrix)
    if determinant == 0:
        return -1

    matrix_minor = []
    for r in range(n):
        matrix_minor_row = []
        for c in range(n):
            matrix_minor_row.append(((-1) ** (r + c)) * get_determinant(get_minor(matrix, r, c)))
        matrix_minor.append(matrix_minor_row)

    res = list(map(list, zip(*matrix_minor)))
    for r in range(n):
        for c in range(n):
            res[r][c] = res[r][c] / determinant
    return res

matrix = [list(map(float, input().split())) for _ in range(int(input()))]
result = inverse(matrix)

if result == -1:
    print("khong co ma tran nghich dao")
else:
    for row in result:
        print(*row)
