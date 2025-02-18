# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:31:59 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    df.insert(2,"price_euros",0.95 * df['price'])
solve()
print(df.head(3))