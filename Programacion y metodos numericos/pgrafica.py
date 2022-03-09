#%%
import matplotlib.pyplot as plt
import numpy as np

a=float(input("Límite inferior a: "))
b=float(input("Límite inferior b: "))
numDatos=int(input("Dame el número de datos en la tabla: "))

vx=np.linspace(a,b,numDatos)
print("Los valores de x son:", vx)
vy=np.exp(-vx)-vx      #f(x)=e(-x)-x
print("Los valores de y son:", vy)

print("x= \t\t y(x)=")
for j in range(numDatos):
    print("{0:.4f}".format(vx[j]), "\t", "{0:.4f}".format(vy[j]))

plt.plot(vx,vy,'r')
plt.grid()
#%%