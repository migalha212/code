# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:24:58 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    pf = df[df['name'] == 'Lewis Hamilton']
    c = pf['status'].value_counts()
    c = c.loc['Finished'] * 100
    print(round(c / pf.shape[0],1))
solve()