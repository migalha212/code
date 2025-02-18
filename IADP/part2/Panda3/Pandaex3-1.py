# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 08:22:19 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'], dayfirst=True)

def solve(name, typea):
    df[name] = df[name].astype(typea)
    print(df.dtypes)

solve('height', float)