# -*- coding: utf-8 -*-
"""
Created on Wed Mar  3 08:50:53 2021

@author: Miguel
"""

import numpy as np
z=0
while z==0:
    i1=int(input("¿Cuántas filas tendrá la matriz A? "))
    j1=int(input("¿Cuántas columnas tendrá la matriz A "))
    i2=int(input("¿Cuántas filas tendrá la matriz B? "))
    j2=int(input("¿Cuántas columnas tendrá la matriz B? "))
    if (i1==i2)and(j1==j2):
        z=1
    else:
        print("Las matrices deben ser simétricas. Volver a introducir datos")
a=np.zeros([i1,j1])
b=np.zeros([i2,j2])
for x in range(2):
    for i in range(i1):
        for j in range(j1):
            if x==0:
                a[i,j]=float(input(f"Valor del elemento {i}, {j} de la matriz A: "))
            else:
                b[i,j]=float(input(f"Valor del elemento {i}, {j} de la matriz B: "))
c=np.zeros([i1,j1])
for i in range(i1):
    for j in range(j1):
        c[i,j]=(a[i,j]+b[i,j])
print("Suma de matrices es igual a: ")
print(c)