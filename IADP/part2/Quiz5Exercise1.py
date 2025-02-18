# -*- coding: utf-8 -*-
"""
Created on Mon Dec 16 23:50:00 2024

@author: migal
"""

import numpy as np


row = int(input("Number of rows ="))
col = int(input("Number of columns ="))


ar = np.zeros((row,col))

for i in range(0,row):
    for j in range(0,col):
        ar[i][j] = int(input("a[" + str(i) + "," + str(j) + "]="))
        
print(f"Determinant = %5.1f" % (np.linalg.det(ar)))

print("Matrix inverse:")
ar = np.linalg.inv(ar)
for i in range(0,row):
    print(ar[i])
