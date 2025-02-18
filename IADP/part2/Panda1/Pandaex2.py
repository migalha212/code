# -*- coding: utf-8 -*-
"""
Created on Wed Dec 18 23:40:30 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'], dayfirst=True)

def solve():
    pf = df
    ag = pf.loc[pf['hours'] > 5]
    print(f'{ag['age'].mean():.2f}')
solve()


