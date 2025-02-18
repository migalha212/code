# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:39:07 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    p = pd.pivot_table(df,'price','city',aggfunc='max')
    print(p.idxmax().loc['price'])
solve()