# -*- coding: utf-8 -*-
"""
Created on Tue Feb 23 08:26:46 2021

@author: Miguel
"""

Datos="si"
while Datos=="si":
    x=int(input("Dame un numero: "))
    if x>0:
        print(x,"Es POSITIVO.")
    elif x==0:
        print(x,"Es CERO.")
    else:
        print(x,"Es NEGATIVO.")
    Opt=input("¿Desea ingresar otro número?: ")
    Opt=Opt.lower()
    if Opt!="si":
        Datos="no"