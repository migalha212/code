# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:45:56 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    print(df[(df['price'] > 2000000) & (df['house_size'] <= 1000)])
solve()