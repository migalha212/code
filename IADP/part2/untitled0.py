# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 11:24:08 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'] , dayfirst=True)


def average(columname):
    s = 0
    n = len(df.loc[columname])
    for i in df.loc[columname]:
        s = s + i
    return s / n


def solve():
    
    pf = df.loc[df['weight'] > 1.3 * df['weight'].mean()]
    print(pf.iloc[:,[1,2,3,4]])
    
    
solve()

