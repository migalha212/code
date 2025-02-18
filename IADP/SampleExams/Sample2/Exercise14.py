# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:48:25 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    pt=df.pivot_table(index='state',columns = 'city', values='price', aggfunc='max')
    pm=pd.DataFrame(pt.idxmax(axis=1))
    print(pm)
    pm['price'] = pt.max(axis=1)
    print(pm)
    pm.rename(columns={0:'City'},inplace =True)
    print(pm)
solve()