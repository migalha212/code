# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:54:08 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    pc = df['Product line'].value_counts()
    print(pc)

solve()