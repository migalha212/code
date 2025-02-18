# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:29:41 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
print(df.shape)
def solve():
    r = df[df['name'] == 'Lewis Hamilton'].index
    df.drop(index=r,inplace = True)
solve()
print(df.shape)