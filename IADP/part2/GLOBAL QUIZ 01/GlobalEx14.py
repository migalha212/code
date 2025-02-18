# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:59:03 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    p = df.loc[df['Total'] > 1030]
    print(p.iloc[:,[4,5,6,7,8]])

solve()