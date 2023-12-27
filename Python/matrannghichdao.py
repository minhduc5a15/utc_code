def minor(mat, r, c):
    return [[mat[i][j] for j in range(len(mat[i])) if j != c] for i in range(len(mat)) if i != r]

def det(mat):
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] if len(mat) == 2 else sum(((-1) ** c) * mat[0][c] * det(minor(mat, 0, c)) for c in range(len(mat)))

def inverse(mat):
    return [[((-1) ** (r + c)) * det(minor(mat, r, c)) / det(mat) for c in range(len(mat))] for r in range(len(mat))] if det(mat) else ["khong co ma tran nghich dao"]

matrix = []
for i in range(int(input())):
    row = list(map(float, input().split()))
    matrix.append(row)

for i in inverse(matrix):
    print(*i)
