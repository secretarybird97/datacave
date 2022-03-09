# -*- coding: utf-8 -*-
"""
Created on Wed Mar 10 08:18:45 2021

@author: Miguel
"""

def triangulo(n):
    '''Genera una figura Triangular o Pirámide formada por números y guiones
    bajos, la variable n ingresada por el usuario representa la cantidad 
    máxima de elementos en el renglón central de la pirámide'''
    x=n-1
    w=n+x
    y=1
    for i in range(1,w+1):
        if i<=n:
            for j in range(i):
                    print(f"{y}", end="")
        elif i>n:
            for j in range(x):
                    print(f"{y}", end="")
            x=x-1
        print("")
triangulo(15)

