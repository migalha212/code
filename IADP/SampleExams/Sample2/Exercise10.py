# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:37:30 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    pf = df[df['house_size'] > 40000]
    print(pf.loc[df['house_size'] > 40000,"city":"house_size"])
solve()