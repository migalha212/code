# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:47:06 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    print(pd.pivot_table(df,'price','state','status',aggfunc='mean').round(1))
solve()