# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:38:55 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    pf = df[df['name'] == 'Lewis Hamilton']
    print(pf['points'].mean().round(1))
solve()