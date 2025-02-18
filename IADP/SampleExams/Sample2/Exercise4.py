# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:25:51 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    pf = df[df['house_size'] > 2000].shape[0]
    print(round(pf/df.shape[0] * 100,1))
solve()