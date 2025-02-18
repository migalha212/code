# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 10:02:06 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    df.drop('Customer type', axis=1, inplace=True)

solve()
print(df.loc[:,'Invoice ID':'Gender'].head(3))