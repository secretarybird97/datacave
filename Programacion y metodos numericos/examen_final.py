#%%
import numpy as np
import matplotlib.pyplot as plt
def trapmul(n):
    """El examen consiste en hacer una funcion que calcule el valor de las
    areas totales generadas por un set de coordenadas.
    Nombre: Miguel Angel Cuevas Gonzalez
    Matricula: #1279713
    2021/05/19""" #DOCSTRING
    k = 0
    x=np.zeros(n)
    y=np.zeros(n)
    A=np.zeros(n-1)
    for i in range(n):
        x[i]=float(input(f"Valor de X{k}: "))
        y[i]=float(input(f"Valor de f({k}): "))
        k = k+1
    print("X | f(X)")
    for i in range(n):
        print(x[i], "|", y[i])
    plt.plot(x, y, '-ok')
    plt.grid()
    print("")
    AT=0
    for i in range(n-1):
        A[i]=((y[i]+y[i+1])*(abs(x[i]-x[i+1])))/2
        print(f"Area de trapecio #{i} = {A[i]}")
        AT = AT+A[i]
    print(f"Area total = {AT}")
trapmul(5)
#%%