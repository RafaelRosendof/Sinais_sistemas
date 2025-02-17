""" 
Métodos de resolução de sistemas lineares 

lu e método de gradientes, tanto em just in time compiler quanto em cuda usando primeiramente o numba 
"""

'''
import numpy as np
from numba import njit

@njit
def decomposicao_lu_pivot(A):
    n, m = A.shape
    if n != m:
        raise ValueError("A matriz deve ser quadrada.")
    
    L = np.eye(n)
    U = A.copy()
    P = np.eye(n)  # Matriz de permutação
    
    for i in range(n):
        # Pivoteamento parcial
        pivot = np.argmax(np.abs(U[i:, i])) + i
        if pivot != i:
            U[[i, pivot]] = U[[pivot, i]]
            P[[i, pivot]] = P[[pivot, i]]
            L[[i, pivot], :i] = L[[pivot, i], :i]
        
        for j in range(i+1, n):
            L[j, i] = U[j, i] / U[i, i]
            U[j] -= L[j, i] * U[i]
    
    return P, L, U

@njit
def resolver_sistema_lu(A, b):
    P, L, U = decomposicao_lu_pivot(A)
    n = len(b)
    
    # Substituição direta (Ly = Pb)
    Pb = np.dot(P, b)
    y = np.zeros(n)
    for i in range(n):
        y[i] = Pb[i] - np.sum(L[i, :i] * y[:i])
    
    # Substituição reversa (Ux = y)
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - np.sum(U[i, i+1:] * x[i+1:])) / U[i, i]

    return x
A = np.array([[4.0, 3.0], [6.0, 3.0]])
b = np.array([10.0, 12.0])
x = resolver_sistema_lu(A, b)
print("Solução:", x)



####################
VERSÃO FEITA EM CUDA PARA GANHO DE DESEMPENHO
import numpy as np
from numba import cuda, float32

@cuda.jit
def lu_cuda_pivot(A, L, U, P, n):
    """
    Decomposição LU com pivoteamento parcial usando CUDA.
    """
    # Indices globais
    i, j = cuda.grid(2)
    
    # Pivoteamento parcial - somente thread 0 faz
    if i == 0 and j == 0:
        for k in range(n):
            pivot = k
            max_val = abs(A[k, k])
            for r in range(k + 1, n):
                if abs(A[r, k]) > max_val:
                    max_val = abs(A[r, k])
                    pivot = r
            if pivot != k:
                # Troca as linhas em A e P
                for col in range(n):
                    A[k, col], A[pivot, col] = A[pivot, col], A[k, col]
                P[k], P[pivot] = P[pivot], P[k]
    
    cuda.syncthreads()

    # Cálculo de L e U
    if i < n and j < n:
        for k in range(n):
            if i == k and j >= k:
                s = 0.0
                for p in range(k):
                    s += L[k, p] * U[p, j]
                U[k, j] = A[k, j] - s
            elif j == k and i > k:
                s = 0.0
                for p in range(k):
                    s += L[i, p] * U[p, k]
                L[i, k] = (A[i, k] - s) / U[k, k]
        cuda.syncthreads()


def resolver_lu_cuda(A):
    n = A.shape[0]
    L = np.eye(n, dtype=np.float32)
    U = np.zeros((n, n), dtype=np.float32)
    P = np.arange(n, dtype=np.int32)  # Vetor de permutação

    # Configuração de threads e blocos
    threadsperblock = (16, 16)
    blockspergrid = ((n + 15) // 16, (n + 15) // 16)

    # Transferência para a GPU
    dA = cuda.to_device(A)
    dL = cuda.to_device(L)
    dU = cuda.to_device(U)
    dP = cuda.to_device(P)

    # Execução do kernel
    lu_cuda_pivot[blockspergrid, threadsperblock](dA, dL, dU, dP, n)

    # Cópia de volta para a CPU
    L = dL.copy_to_host()
    U = dU.copy_to_host()
    P = dP.copy_to_host()

    return P, L, U


A = np.array([[4.0, 3.0], [6.0, 3.0]], dtype=np.float32)
P, L, U = resolver_lu_cuda(A)

print("Matriz de Permutação P:", P)
print("Matriz L:\n", L)
print("Matriz U:\n", U)


'''