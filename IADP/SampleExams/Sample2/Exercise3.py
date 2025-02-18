# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:24:03 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    df.loc[2,["status","price"]] = ["sold",60000]
solve()
print(df.head(3))