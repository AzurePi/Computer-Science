import math

N = 4

A = [[2.0, 1.0, 0.0, -3.0],
     [1.0, -1.5, -7.5, 0.5],
     [-2.0, 1.0, 1.5, 2.0],
     [-1.0, -4.5, 1.0, 1.5]]

G = [[] for _ in range(N)]

for i in range(N):
    for j in range(N):
        G[i].append(0)

k = 0
teste = 0
val = A[k][k]
if val > 0:
    G[k][k] = math.sqrt(val)
    if k == N - 1:
        teste = 0
else:
    teste = -k

while teste > 0:
    for i in range(k, N):
        ss = 0.0
        for j in range(0, k):
            ss += G[k][j] * G[i][j]
        G[i][k] = (A[i][k] - ss) / G[k][k]
    k += 1
    ss = 0.0
    for j in range(0, k):
        ss += G[k][j] * G[k][j]
    val = A[k][k] - ss
    if val > 0:
        G[k][k] = math.sqrt(val)
        if k == N:
            teste = 0
        else:
            teste = -k
