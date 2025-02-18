# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 13:05:50 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    pf = df[(df['salary'] > 240000) & (df['race'] == 'Black')]
    print(pf.loc[:,"race":"salary"])
solve()