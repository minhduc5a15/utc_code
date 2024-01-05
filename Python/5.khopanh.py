def contains(matrixA, matrixB):
    rowsA, colsA = len(matrixA), len(matrixA[0])
    rowsB, colsB = len(matrixB), len(matrixB[0])
    for i in range(rowsA - rowsB + 1):
        for j in range(colsA - colsB + 1):
            if all(matrixA[i+p][j+q] == matrixB[p][q] for p in range(rowsB) for q in range(colsB)):
                return True
    return False
n, m = list(map(int, input().split()))
matrixA, matrixB = [], []
for i in range(n):
    itemA = input()
    matrixA.append(list(itemA))
for i in range(m):
    itemB = input()
    matrixB.append(itemB)

print("Yes" if contains(matrixA, matrixB) else "No")  
