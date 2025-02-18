# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:34:25 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    print(df["status"].value_counts())
solve()