# -*- coding: utf-8 -*-
"""
Created on Wed Mar 17 08:04:29 2021

@author: Miguel
"""

import numpy as np
Opt1="si"
while Opt1=="si":
    n=int(input("Ingresa el número de elementos del vector: "))
    a=np.empty(n)
    for i in range(n):
        a[i]=float(input(f"Ingresa el valor del elemento {i}: "))
    print("\t")
    print("Contenido del vector: ")
    for i in range(n):
        print(f"{a[i]}, ", end="")
    Opt=0
    S=0
    m=0
    print("\n")
    while Opt==0:
        Op=int(input("¿Qué desea conocer/hacer?\nPromedio de los elementos dentro del vector (1), Cuántas veces esta repetido cada valor (2): "))
        if Op==1:
            for i in range(n):
                S=S+a[i]
            P=S/n
            print("Promedio de los elementos: ", P)
            Opt=1
        elif Op==2:
            b=np.full(n,0)
            for i in range(n):
                for j in range(n):
                    if a[i]==a[j]:
                        b[i]=b[i]+1
            for i in range(n):
                print(f"Hay {b[i]} '{a[i]}'s en el vector")
            Opt=1
        else:
            print("Opción invalida")
    Opt1=input("¿Desea volver a correr el programa? ")
    Opt1=Opt1.lower()