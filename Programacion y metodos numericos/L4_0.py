# -*- coding: utf-8 -*-
"""
Created on Wed Mar 10 08:09:37 2021

@author: Miguel
"""

import math
def senod(x):
    '''Regresa el seno de un valor x, en grados'''
    y=x*(math.pi/180)
    return math.sin(y)

print(senod(45))