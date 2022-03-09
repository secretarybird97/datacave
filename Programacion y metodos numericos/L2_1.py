# -*- coding: utf-8 -*-
"""
Created on Wed Mar  3 08:36:03 2021

@author: Miguel
"""

import numpy as np
m=0
n=int(input("Ingresa el número de elementos del vector: "))
a=np.empty(n)
for i in range(n):
    a[i]=float(input(f"Ingresa el valor del elemento {i}: "))
x=float(input("¿Qué valor desea buscar en el vector: "))
for i in range(n):
    if a[i]==x:
        m=m+1
if m>0:
    print(f"Se encontró {x}, {m} veces en el vector")
else:
    print(f"No se encontró {x} en el vector")