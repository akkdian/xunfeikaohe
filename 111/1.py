import numpy as np

def inverse_matrix(matrix):
    try:
        inv_matrix = np.linalg.inv(matrix)
        return inv_matrix
    except np.linalg.LinAlgError:
        raise ValueError('矩阵不可逆')
n=int(input("Enter the matrix size\n"))

import numpy as np

mat=np.zeros((n,n))
for i in range(n):
    mat[i]=input().split(" ")

inv_matrix = inverse_matrix(mat)
print(inv_matrix)
