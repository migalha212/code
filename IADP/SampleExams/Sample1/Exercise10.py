# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 13:00:19 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    pf = df['status'].value_counts(normalize=True) * 100
    print(pf.round(1))
solve()