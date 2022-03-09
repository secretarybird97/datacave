# -*- coding: utf-8 -*-
"""
Created on Wed Mar  3 08:07:32 2021

@author: Miguel
"""

import numpy as np
a=np.zeros(3)
b=np.zeros(3)
for x in range(2):
    for y in range(3):
        if x==0:
            a[y]=float(input(f"Ingresa el elemento {y} del vector A: " ))
        else:
            b[y]=float(input(f"Ingresa el elemento {y} del vector B: " ))
print("Vector A: ", a)
print("Vector B: ", b)
Op=0
while Op==0:
    P=int(input("¿Qué desea realizar? Producto Punto (0) o Producto Cruz (1): "))
    if P==0:
        PP=(a[0]*b[0])+(a[1]*b[1])+(a[2]*b[2])
        print("Producto Punto: ", PP)
        Op=1
    elif P==1:
        i=(a[1]*b[2])-(a[2]*b[1])
        j=(a[2]*b[0])-(a[0]*b[2])
        k=(a[0]*b[1])-(a[1]*b[0])
        PC=np.array([i,j,k])
        print("Producto Cruz: ", PC)
        Op=1
    else:
        print("Opción invalida")