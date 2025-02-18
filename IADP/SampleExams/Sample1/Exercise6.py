# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:31:04 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    global df
    pf = df[df['salary'] > 150000]
    count1 = pf.shape[0]
    vf = pf[pf['education'] >= 13]
    count2 = vf.shape[0]
    print(count1)
    print(count2)
solve()