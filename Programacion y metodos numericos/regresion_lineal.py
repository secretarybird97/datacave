# Miguel Cuevas 1279713

#%%
import matplotlib.pyplot as plt
import numpy as np

def print_ecuacion(m,b): 
    """Imrpime una ecuacion lineal de tipo
    y = mx +b
    """
    print(f"m es igual a {m}")
    print(f"b es igual a {b}")
    if b>0:
        print(f"Ecuación: y = {m}x + {b}")
    elif b<0:
        print(f"Ecuación: y = {m}x {b}")
    else:
        print(f"Ecuación de la recta: y = {m}x")
        
def main(): #FUNCION PRINCIPAL
    n = int(input("Cantidad de coordenadas en la muestra:"))
    x = np.zeros([n])
    y = np.zeros([n])
    k = 0 #contador
    for i in range(n):
        x[i]=float(input(f"Valor de X{k}: "))
        y[i]=float(input(f"Valor de Y{k}: "))
        k = k+1
        
    sumx=0
    sumy=0
    sumxy=0
    sumx2=0
    for i in range(n): #formula de regresion lineal
        sumx = sumx+x[i]
        sumy = sumy+y[i]
        sumxy = sumxy + x[i]*y[i]
        sumx2 = sumx2 + (x[i])**2
    m = (n*sumxy-sumx*sumy)/(n*sumx2-sumx**2)
    b = (sumy-m*sumx)/n
    
    print_ecuacion(m,b)
    plt.plot(x, y, 'o')
    plt.plot(x, m*x + b)
    plt.grid()

if __name__ == '__main__':
    main()
#%%