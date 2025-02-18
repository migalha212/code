# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:30:26 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    f =  df.loc[df['Gender'].isin(['Female'])]
    print(f['Total'].mean().round(1))

solve()