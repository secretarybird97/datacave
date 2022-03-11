#%%
'''Miguel Cuevas - #1279713'''
import matplotlib.pyplot as plt
import matplotlib.image as img

def matriz(x,y):
    k=[[0 for i in range(x)] for j in range(y)]
    return k

def crear_mapa(x, y, obj):
    plt.imshow(obj)
    plt.show()
    R=matriz(x,y)
    G=matriz(x,y)
    B=matriz(x,y)
    for i in range(x):
        for j in range(y):
            R[i][j]=obj[i][j][0]
            G[i][j]=obj[i][j][1]
            B[i][j]=obj[i][j][2]
    plt.matshow(R,cmap='Greys')
    plt.matshow(G,cmap='Greys')
    plt.matshow(B,cmap='Greys')
    lista = [R,G,B]
    return lista
    
def mapa_bordes(x, y, mapa):
    D1=matriz(x,y)
    D2=matriz(x,y)
    D3=matriz(x,y)
    D4=matriz(x,y)
    bordes=matriz(x,y)

    for i in range(1, x-2):
        for j in range(1, y-2):
            z1=mapa[0][i-1][j-1]
            z2=mapa[0][i][j-1]
            z3=mapa[0][i+1][j-1]
            z4=mapa[0][i-1][j]
            z5=mapa[0][i][j]
            z6=mapa[0][i+1][j]
            z7=mapa[0][i-1][j+1]
            z8=mapa[0][i][j+1]
            z9=mapa[0][i+1][j+1]
            D1[i][j]=(((z5-z2)**2)+((z5-z8)**2))**0.5
            D2[i][j]=(((z5-z4)**2)+((z5-z6)**2))**0.5
            D3[i][j]=(((z5-z1)**2)+((z5-z9)**2))**0.5
            D4[i][j]=(((z5-z3)**2)+((z5-z7)**2))**0.5
            bordes[i][j]=D1[i][j] +D2[i][j] +D3[i][j] +D4[i][j]
    plt.matshow(bordes,cmap='Greys')
            


imagen=img.imread('pintura.jpeg')
cuadricula=crear_mapa(300,300,imagen)
mapa_bordes(300,300,cuadricula)

#%%