# -*- coding: utf-8 -*-
"""
Created on Wed Feb 24 08:09:32 2021

@author: Miguel
"""

Opt="si"
while Opt=="si":
    n=int(input("Intrduzca un número: "))
    for i in range(1,13):
        print(f"{n} por {i} es igual a: ", i*n)
    Opt=input(("¿Desea ingresar otro número? "))
    Opt=Opt.lower()
    if Opt!="si":
        Opt="no"