# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:38:16 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    print(df['Total'].describe().round(2))
    
solve()