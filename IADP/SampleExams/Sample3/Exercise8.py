# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:33:28 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    pf = df['name'].value_counts()
    print(pf.head(5).sort_index(axis=0))
solve()