#%%
#Creador: Gonzalez Rocha Jesus Daniel
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
fig, ax = plt.subplots()
distancia= float(input("Distancia entre placas en mm: "))
distancia=distancia/1000
area= float(input("Area de las placas en mm^2: "))
area = area/(1*10**6)
ep = 8.854187817*10**-12
w=-0.15
v=1.5
voltajes = np.zeros((11))
cargas = np.zeros((11))
cap=(ep*area)/distancia
energias = np.zeros((11))

tabla=[]

for i in range(11):    
    voltajes[i] = v+(w*i)
    cargas[i] = cap*voltajes[i]
    energias[i] = (1/2)*cap*(voltajes[i]**2)
    tabla.append([voltajes[i],cargas[i],energias[i]])
    
plt.plot(voltajes,cargas, linestyle = 'dotted',color='tab:orange')
plt.xlabel('Voltaje[V]',fontdict={'color':'tab:blue'})
plt.ylabel('Carga de la placa[C]',fontdict={'color':'tab:blue'})
plt.title('Carga de la placa respecto al voltaje',loc='left',fontdict={'fontweight':'bold'})
plt.show()
plt.plot(voltajes,energias, linestyle = 'dotted',color='tab:orange')
plt.xlabel('Voltaje[V]',fontdict={'color':'tab:blue'})
plt.ylabel('Energia almacenada[J]',fontdict={'color':'tab:blue'})
plt.title('Energia almecanda respecto al Voltaje',loc='left',fontdict={'fontweight':'bold'})
plt.show()
print(f"\nCapacitancia[F] = {cap}")
tablaPandas = pd.DataFrame(tabla,columns=["Voltaje","Carga [C]","Energia [J]"])
print(tablaPandas)

#%%
