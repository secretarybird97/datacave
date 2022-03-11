#%%
'''Miguel Cuevas - #1279713'''
import matplotlib.pyplot as plt
def cuadricula(x, y):
    a = y
    b = x
    cuadricula = list()
    for i in range(a):
        cuadricula2=list()
        for j in range(b):
            if (((i==23) and (j==23)) or ((i==23) and (j==24)) or ((i==24) and (j==24)) or ((i==24) and (j==25)) or ((i==25) and (j==25)) or ((i==25) and (j==26))):
                cuadricula2.append(1)
            else:
                cuadricula2.append(0)
        cuadricula.append(cuadricula2)
    return cuadricula

def imprimir_cuadricula(matriz):
    plt.imshow(matriz)
    plt.show()

a = 50 #alto
b = 50 #ancho
cuadricula = cuadricula(a, b)

imprimir_cuadricula(cuadricula)
for r in range(50):
    dup=list()
    for i in range(a):
        dup2=list()
        for j in range(b):
            vecinos=0
            for y in range(i-1,i+2):
                for x in range(j-1,j+2):
                    if (y<a and y>=0) and (x<b and x>=0) and (cuadricula[y][x]==1):
                        vecinos+=1
            if(cuadricula[i][j]==1):
                vecinos-=1
            if(cuadricula[i][j]==1)and(vecinos>=4):
                dup2.append(0)
            elif(cuadricula[i][j]==1)and(vecinos<=1):
                dup2.append(0)
            elif(cuadricula[i][j]==1)and(vecinos==2 or vecinos==3):
                dup2.append(1)
            elif(cuadricula[i][j]==0) and (vecinos==3):
                dup2.append(1)
            else:
                dup2.append(0)
        dup.append(dup2)
    
    cuadricula = list()
    cuadricula = dup
    imprimir_cuadricula(cuadricula)
#%%