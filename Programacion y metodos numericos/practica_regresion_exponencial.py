#%%
import math
import matplotlib.pyplot as plt
import numpy as np
n = int(input("Cantidad de coordenadas en la muestra:"))
x = np.zeros([n])
y = np.zeros([n])
k = 0
for i in range(n):
    x[i]=float(input(f"Valor de X{k}: "))
    y[i]=float(input(f"Valor de Y{k}: "))
    k = k+1

sumx=0
sumlny=0
sumxlny=0
sumx2=0
for i in range(n):
    sumx = sumx+x[i]
    sumlny = sumlny+math.log(y[i])
    sumxlny = sumxlny+x[i]*math.log(y[i])
    sumx2 = sumx2+(x[i])**2
B = (n*sumxlny-sumx*sumlny)/(n*sumx2-sumx**2)
lnA = (sumlny-B*sumx)/n
A = np.exp(lnA)
print(f"Ecuación de la recta: y = {A}e^{B}x")
plt.plot(x, y, 'o')
plt.plot(x, A*np.exp(B*x))
plt.grid()
#%%