# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:46:31 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    global df
    cf = df[(df['position'] <=3) & (df['year'] >= 2018)]
    p = pd.pivot_table(cf,values='year',index='name',columns='position',aggfunc='count')
    print(p)
solve()