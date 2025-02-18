# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 00:20:11 2024

@author: migal
"""

import numpy as np

i = float(input("Initial value:"))
f = float(input("Final value:"))
n = int(input("Number of values:"))


ar = np.linspace(i,f,n)
ar = np.square(ar)
print("Sum of the array: %.2f" % (np.sum(ar)))