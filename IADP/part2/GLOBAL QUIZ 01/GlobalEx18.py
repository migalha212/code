# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 10:06:42 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    p = df.loc[df['Customer type'].isin(['Member']) & df['Gender'].isin(['Male']) & df['Unit price'] > 99]
    print(p.iloc[2:6,:])

solve()