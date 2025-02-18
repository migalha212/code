# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:33:19 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def hif_und(name):
    return name.replace('-','_')
print(hif_und('very-high'))
def solve():
    global df
    df['status]'] = df['status'].apply(hif_und)
    
solve()
print(df.loc[:,'age':'status'].head(3))