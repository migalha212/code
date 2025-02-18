# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:10:15 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    df.loc[2,'Customer type'] = 'Member'
    
 
solve()
print(df.loc[:,'Invoice ID':'Gender'].head(3))