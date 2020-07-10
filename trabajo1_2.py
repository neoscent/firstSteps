# por Daniel Parra P. y Marco Salgado M.
# 9.6.20
# Trabajo 1: (b) Mayor Matriz Cuadrada Nula
# Tested with Python 3.7.6 on MacOS
# Text Editor: Atom 1.47.0

def searchMax(A, maxZero):
    currentMax = [0,0]
    countElem = 0
    for x in range (1, maxZero+1):
        for y in range (0, len(A)):
            if A[y][1] >= x:        #Se cuentan la cantidad de elementos que poseen al menos x cantidad de ceros
                temp_y = A[y][0]
                while y < len(A) and A[y][1] >= x:
                    countElem+=1
                    y+=1
            if y >= len(A)-1 or A[y][1] < x:
                if countElem == x:
                    if countElem*x > currentMax[0]*currentMax[1]: # Dependiendo de la funcion de la cual searchMax()
                        currentMax[0] = countElem                 # haya sido llamada, countElem y 'x' corresponden a filas y columnas o viceversa
                        currentMax[1] = temp_y
                countElem = 0
            y+=1
    return currentMax

def greaterHeight(M):
    dim = 0
    A=[]
    for j in range (0, len(M[0])):
        for i in range (0, len(M)):
            maxZero = 0
            if M[i][j] == 0:        # Si el elemento es igual a 0
                while i < len(M) and M[i][j] == 0:  #Se cuentan los 0 adyacentes, dentro de la misma columna
                    countCol = 0
                    k = 0
                    while k < len(M[0])-j and M[i][j+k] == 0: #Por cada elemento 0, se cuentan cuantos 0 hay hacia la derecha
                        if M[i][j+k] == 0:
                            countCol += 1
                        k+=1
                    A.append([i, countCol])
                    if maxZero < countCol:
                        maxZero = countCol
                    i+=1
            temp_dim, temp_x = searchMax(A, maxZero)
            while len(A)>0:      # Se vacia la lista
                A.pop()
            if temp_dim > dim:   # Si la matriz encontrada tiene mayores dimensiones...
                dim = temp_dim
                x = temp_x
                y = j
    tuple = (x, y, dim)
    return tuple

def greaterWidth(M):
    dim = 0
    A=[]
    for i in range (0, len(M)):
        for j in range (0, len(M[0])):
            maxZero = 0
            if M[i][j] == 0:        # Si el elemento es igual a 0
                while j < len(M[0]) and M[i][j] == 0: #Se cuentan los 0 adyacentes, dentro de la misma fila
                    countRow = 0
                    k = 0
                    while k < len(M)-i and M[i+k][j] == 0: #Por cada elemento 0, se cuentan cuantos 0 hay hacia abajo
                        if M[i+k][j] == 0:
                            countRow += 1
                        k+=1
                    A.append([j, countRow])
                    if maxZero < countRow:
                        maxZero = countRow
                    j+=1
            temp_dim, temp_y = searchMax(A, maxZero)
            while len(A)>0: # Se vacia la lista
                A.pop()
            if temp_dim > dim: # Si la matriz encontrada tiene mayores dimensiones...
                dim = temp_dim
                x = i
                y = temp_y
    tuple = (x, y, dim)
    return tuple

def maxMatrix(M):                       # Funcion principal
    if (len(M)>len(M[0])):              # Si hay mas filas que columnas
        print(greaterHeight(M))
    else:                               # Si hay mas columnas que filas o si ambas son iguales
        print(greaterWidth(M))
