# -*- coding: utf-8 -*-
"""
Created on Wed Mar 10 08:23:49 2021

@author: Miguel
"""

def primo(num):
    '''Despliegue un mensaje que determina si el número ingresado por el
    usuario es PRIMO o NO'''
    p=True
    if num!=1:
        for i in range(2,num):
            if num%i==0:
                p=False
        if p==True:
            print(f"{num} es PRIMO")
        else:
            print(f"{num} NO es PRIMO")
    else:
        print("El 1 No es PRIMO")

primo(18)
primo(19)