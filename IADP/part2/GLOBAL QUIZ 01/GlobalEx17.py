# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 10:04:12 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    global df
    
    # Delete rows where 'City' is 'Yangon'
    df = df[df['City'] != 'Yangon']


solve()
print(df.loc[:,'Invoice ID':'Product line'].head(3))