# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:20:17 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    global df
    df = df[df['salary'] >= 150000]
    count = df[df['status'].str.startswith('Married')].shape[0]
    c2 = df['status'].shape[0]
    perc = count / c2 * 100
    print(f"{perc:.1f}%")
solve()