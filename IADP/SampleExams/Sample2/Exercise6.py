# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:28:58 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
print(df.shape)
def solve():
    global df
    df = df[df['price'] < 800000]
solve()
print(df.shape)