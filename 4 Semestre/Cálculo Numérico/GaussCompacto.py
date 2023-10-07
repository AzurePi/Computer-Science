import numpy as np

def decomposiçao_A_para_LU(matriz):
  """
  Decompõe uma matriz em L e U e retorna LU compacto, o vetor permutaçao, e o sinal do determinante
  """

  tam = len(matriz) #tamanho
  perm = [i for i in range(tam)] #vetor de permutaçao

  sinal = 1 #sinal do determinante, utilizado para multiplicar no final

  for i in range(tam):

    #pivoteamento
    maior = i
    for a in range(i+1, tam):
      if (abs(matriz[a][i]) > abs(matriz[maior][a])):
        maior = a
    if (maior > i):
      troca_linha(matriz, i, maior) #troca linha da matriz
      troca_linha(perm, i, maior) #troca linha do vetor de permutaçao
      sinal = -sinal #sinal do det

    pivo = matriz[i][i]

    for j in range(i + 1, tam):
            coeficiente = matriz[j][i] / pivo

            for k in range(i+1, tam):
                matriz[j][k] -= coeficiente * matriz[i][k] #eliminaçao
            matriz[j][i] = coeficiente #armazena o coeficiente

  return matriz, perm, sinal #retorna alteraçoes


def troca_linha(matriz, linha1, linha2):
  """
  Troca a posiçao de duas linhas
  """

  matriz[linha1], matriz[linha2] = matriz[linha2], matriz[linha1]


def resolver_sistema(matriz, vetorB, vetorPerm):
  """
  Resolve o novo sistema Ly = b e Ux = y
  """

  tam = len(matriz)

  #operaçao Ly = b
  y = [0.0] * tam
  y[0] = vetorB[vetorPerm[0]]

  for i in range(1, tam):
      soma = 0.0
      for j in range(i):
          soma += y[j] * matriz[i][j]
      y[i] = vetorB[vetorPerm[i]] - soma


  #operaçao Ux = y
  if(matriz[tam - 1][tam - 1] == 0): #divisao por 0
    return -1

  x = [0] * tam
  x[tam - 1] = y[tam - 1] / matriz[tam - 1][tam - 1]

  for i in range(tam - 2, -1, -1):
      soma = 0.0
      for j in range(i + 1, tam):
          soma += x[j] * matriz[i][j]
      x[i] = (y[i] - soma) / matriz[i][i]

  return x #retorna vetor X


def determinante(matriz, sinal):
  """
  Calcula o determinante da matriz
  """
  det = sinal
  for i in range(len(matriz)):
      det *= matriz[i][i]
  return det

#-------------------------------------------------------------------------------
def print_matrix(matriz):
    n = len(matriz)

    for i in range(n):
      for j in range(n):
        print("{:.3f}".format(matriz[i][j]), end="\t")
      print("")

def print_vetor(vetor):
    n = len(vetor)

    for i in range(n):
      print("{:.3f}".format(vetor[i]))


#-------------------------------------------------------------------------------
def exemplo():
  matriz = [[2, 3, 4],[3, 2, -1],[5, -4, 3]]
  vetorB = [-2, 4, 8]

  matriz_resultado, vetorPerm, sinal = decomposiçao_A_para_LU(matriz)
  print("\nMatriz LU:")
  print_matrix(matriz_resultado)

  resolucao = resolver_sistema(matriz, vetorB, vetorPerm)
  if(resolucao == -1):
    print("\nERRO: Divisao por 0!")
  else:
    print("\nVetor Resoluçao:")
    print_vetor(resolucao)

    det = determinante(matriz, sinal)
    print("\nDeterminante:", det)


def insere():
  print("Dimensão do sistema: ", end="")
  n = int(input())

  if(n < 1):
    print("ERRO: Dimensão inválida")
    return

  A = [[] for _ in range(n)]

  print("\nInsira os coeficientes do sistema")

  for i in range(n):
    for j in range (n):
      print(f"A[{i+1}][{j+1}] = ", end="")
      A[i].append(float(input()))

  matriz_resultado, vetorPerm, sinal = decomposiçao_A_para_LU(A)
  print("\nMatriz LU:")
  print_matrix(matriz_resultado)

  while True:
    b = []
    print("\nInsira os resultados da equação")

    for i in range(n):
      print(f"b[{i+1}] = ", end="")
      b.append(float(input()))

    resolucao = resolver_sistema(A, b, vetorPerm)
    if(resolucao == -1):
      print("\nERRO: Divisao por 0!")
      return
    else:
      print("\nVetor Resoluçao:")
      print_vetor(resolucao)

      det = determinante(A, sinal)
      print("\nDeterminante:", det)


    print("\nResolver o sistema para outros valores (\"S\" para continuar)? ", end="")
    resp = input().upper()
    if(resp != "S"):
      break

  return


# ------------------------------------------------------------------------------
while True:
  print("1. Exemplo")
  print("2. Inserir valores")
  print("0. Encerrar")
  op = input()

  if(op == '1'):
    exemplo()
    print("\n")
  elif(op == '2'):
    print("")
    insere()
    print("\n")
  elif(op == '0'): break