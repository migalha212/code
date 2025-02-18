# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 13:16:52 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    pf = pd.pivot_table(df,values='age',index='status',columns='sex',aggfunc='mean')
    print(pf.round(1))
solve()