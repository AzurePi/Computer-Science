N = 4

A = [[2.0, 1.0, 0.0, -3.0],
     [1.0, -1.5, -7.5, 0.5],
     [-2.0, 1.0, 1.5, 2.0],
     [-1.0, -4.5, 1.0, 1.5]]

L = [[] for _ in range(N)]
U = [[] for _ in range(N)]

for i in range(N):
    for j in range(N):
        L[i].append(0)
        U[i].append(0)

for j in range(N):
    U[0][j] = A[0][j]
for i in range(1, N):
    L[i][0] = A[i][0] / U[0][0]

for k in range(1, N - 1):
    for j in range(k, N):
        sj = 0.0
        for ir in range(0, k):
            sj += L[k][ir] * U[ir][j]
        U[k][j] = A[k][j] - sj
    for i in range(k + 1, N):
        si = 0.0
        for ir in range(0, k):
            si += L[i][ir] * U[ir][k]
        L[i][k] = (A[i][k] - si) / U[k][k]

sj = 0.0
for ir in range(0, N - 2):
    sj += L[N-1][ir] * U[ir][N-1]
U[N-1][N-1] = A[N-1][N-1] - sj
