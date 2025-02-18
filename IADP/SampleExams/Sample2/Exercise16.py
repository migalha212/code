# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:58:50 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
import datetime as dt
def solve():
    def ndias(date):
        td = dt.datetime(2022,6,27)
        dp = pd.to_datetime(date)
        return (td - dp).days
    df['days'] = df['sold_date'].apply(ndias)
solve()
print(df[~df['sold_date'].isna()].head(3))