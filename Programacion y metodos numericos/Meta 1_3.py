# -*- coding: utf-8 -*-
"""
Created on Tue Feb 23 08:26:46 2021

@author: Miguel
"""

NP=0
NN=0
N0=0
n=int(input("¿Cuantos valores quieres ingresar?: "))
for j in range(1,n+1):
    x=int(input("Dame un numero: "))
    if x>0:
        print(x,"Es POSITIVO.")
        NP=NP+1
    elif x==0:
        print(x,"Es CERO.")
        N0=N0+1
    else:
        print(x,"Es NEGATIVO.")
        NN=NN+1
print(NP, "Números positivos; ", NN, "Números negativos; ", N0, "Números cero")