# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:52:56 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    print(df.iloc[[0,2],[0,8]])
    
solve()