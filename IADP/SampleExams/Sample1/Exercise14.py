# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 13:19:52 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    pf = pd.pivot_table(df,values='age',index='status',columns='race',aggfunc='mean').round(1)
    m = pf.max().max()
    status,race = pf.stack().idxmax()
    print(f"{status}, {race}, {m}")
solve()