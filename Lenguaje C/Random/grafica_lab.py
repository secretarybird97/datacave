#%%
#Creador: Gonzalez Rocha Jesus Daniel
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()
resultados = np.zeros((11))
distancias = np.zeros((11))
k = 8.98755*(10**9)
p = 0.5 #distancia inicial respecto a la carga positiva
n=5.5 #distancia inicial respecto a la carga negativa

for i in range(11):
    distancias[i] = p
    resultados[i] = k *(((3*10**-9)/(p))+((-1*10**-9)/(n)))
    p=p+0.5
    n=n-0.5
plt.plot(distancias,resultados, linestyle = 'dotted',color='tab:orange')
plt.xlabel('Distancia[m]',fontdict={'color':'tab:blue'})
plt.ylabel('Voltaje[V]',fontdict={'color':'tab:blue'})
plt.title('Comportamiento de Voltaje respecto a distancia',loc='left',fontdict={'fontweight':'bold'})
plt.show()
#%%

'''16.64
7.236
4.052
2.243
1.029
0.006
-1.004
-2.211
-3.953
-7.237
-16.03'''