# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:27:46 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    pf = df['house_size'].describe()
    print(pf)
solve()