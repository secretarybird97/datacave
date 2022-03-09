#%%
import matplotlib.pyplot as plt
import numpy as np
X0=float(input("Valor de X0: "))
Y0=float(input("Valor de Y0: "))
X1=float(input("Valor de X1: "))
Y1=float(input("Valor de Y1: "))
xq=float(input("Valor de x a interpolar: "))
m=(Y1-Y0)/(X1-X0) #Pendiente
b=(m*-X0)+Y0 #Valor de b
print(f"m es igual a {m}")
print(f"b es igual a {b}")
if b>0:
    print(f"Ecuación: y = {m}x + {b}")
if b<0:
    print(f"Ecuación: y = {m}x {b}")
else:
    print(f"Ecuación de la recta: y = {m}x")
Yx=m*xq +b #Ecuación de la recta
print(f"Valor de y cuando x vale {xq} = {Yx}")
plt.plot(xq,Yx)
plt.grid()
#%%