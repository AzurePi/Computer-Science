CYAN = "\033[36m"
GREEN = "\033[32m"
RESET = "\033[0m"


def imprimir(A, b, x, n):
    """

    :param A: Matriz dos coeficientes das equações
    :param b: Matriz dos resultados de cada equação
    :param x: Matriz dos valores das incógnitas
    :param n: Número de equações
    """
    for i in range(n):
        for j in range(n):
            print(str(A[i][j]), end="\t")
        print(CYAN + str(b[i]) + "\t" + GREEN + str(x[i]) + RESET)


N = 3

###########################

A = [[1, 1, 1], [-3.5, 2, 1], [1.5, 2, -1]]
b = [0, 0, 1]

x = [0, 0, 0]

###########################

k = 0
while k < N:

    max = k
    for i in range(k + 1, N):
        if abs(A[i][k]) > abs(A[max][k]):
            max = i

    if max > k:
        for i in range(k, N):
            temp = A[k][i]
            A[k][i] = A[max][i]
            A[max][i] = temp
        temp = b[k]
        b[k] = b[max]
        b[max] = temp

    for i in range(k + 1, N):
        mult = A[i][k] / A[k][k]
        for j in range(k, N):
            A[i][j] = A[i][j] - (mult * A[k][j])
        b[i] = b[i] - (mult * b[k])
    k = k + 1

    x[N - 1] = b[N - 1] / A[N - 1][N - 1]
    for i in range(N - 1, 0, -1):
        sum = 0
        for j in range(i, N):
            sum = sum + A[i][j] * x[j]
        x[i] = (b[i] - sum) / A[i][j]

imprimir(A, b, x, N)
