# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 14:54:16 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('usa_real_estate1.csv', sep=';',parse_dates=['sold_date'])
def solve():
    bi = [0,1000,2000,3000,5000,10000]
    l = ["very_small","small","medium","large","very_large"]
    print(pd.cut(df['house_size'],bins=bi,labels=l,right=False).value_counts())
solve()