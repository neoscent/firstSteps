# por Daniel Parra Ponce y Marco Salgado Munizaga
# 9.7.28
# Trabajo 1: (c) Celdas Libres
# Tested with Python 3.7.6 on MacOS
# Text Editor: Atom 1.47.0

def isFree (m,i,j,queue): # Revisa si la celda es libre
    redflag = 0
    tempQueue=[]
    for x in range (i-1,i+2):
        if x >= 0 and x < len(m):
            for y in range (j-1, j+2):
                if y >= 0 and y < len(m[0]):
                    tempQueue.append([x, y])
                    if (m[x][y]==1): #Si la celda vecina es 1
                        redflag = 1  # la bandera cambia indicando que no es celda libre
    if redflag==0:
        print([i,j])
        for x in range (0, len(tempQueue)):
            addTo(queue,tempQueue[x])
    else:
        emptyList(tempQueue)

def emptyList (list):
    for x in range (0, len(list)):
        list.pop()

def addTo(list, elem):
    redflag = 0
    for x in range (0, len(list)):
        if(list[x]==elem):
            redflag = 1
    if redflag == 0:
        list.append(elem)

def check(x, queue, m):
    for i in range (x, len(queue)):
        isFree(m,queue[i][0],queue[i][1],queue)
        length = len(queue)
    return (i, length)

def main(m,i_c,j_c):
    queue=[]
    x = 0
    redflag=0
    queue.append([i_c,j_c])
    while redflag == 0:
        x, length = check(x, queue, m)
        x+=1
        if x >= length-1:
            redflag=1
