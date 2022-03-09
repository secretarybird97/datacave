# -*- coding: utf-8 -*-
"""
Created on Wed Feb 24 08:16:41 2021

@author: Miguel
"""

for i in range(1,5):
    for j in range(1,6):
        if j==i:
            print("o", end="")
        else:
            print("_", end="")
    print("\n")