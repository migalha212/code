# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 00:12:25 2024

@author: migal
"""

import numpy as np

n = int(input())
m = int(input())
p = int(input())

ar1 = np.zeros((n,m))
ar2 = np.zeros((m,p))

for i in range(0,n):
    for j in range(0,m):
        ar1[i][j] = int(input())
        
for i in range(0,m):
    for j in range(0,p):
        ar2[i][j] = int(input())
        
ar = np.dot(ar1,ar2)

for i in range(0,len:
    print(ar[i])
        