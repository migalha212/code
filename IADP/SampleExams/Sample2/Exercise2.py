# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:19:00 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    global df
    dele = df.loc[:,"bed":'acre_lot'].columns
    df.drop(columns=dele,inplace=True)
solve()
print(df.head(3))