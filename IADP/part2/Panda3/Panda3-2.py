# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 08:23:04 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'], dayfirst=True)

def solve():
    age = df['age'].max()
    f = df.loc[df['age'] == age]
    f = f['name'].str.split(' ',expand=True)
    
    
    
    
solve()