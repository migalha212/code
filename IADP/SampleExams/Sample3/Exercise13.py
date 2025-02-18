# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:53:48 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    c = df[df['year'] >= 2018]
    p = pd.pivot_table(c,values='points',index='year',columns='name',aggfunc='max')
    pm = pd.DataFrame(p.idxmax(1))
    pm.insert(0,"points",p.loc[p.idxmax(1)[0]])
    print(p.max())
solve()