# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:40:15 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    pf = df[df['year'] == 2021]
    d = pf['dob'].idxmin()
    print(pf.loc[d,"name"])
solve()