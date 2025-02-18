# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:18:29 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    df.loc[2,['status','points']] = ['Engine',0]
solve()
print(df.loc[:,'name':'status'].head(3))