# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 00:08:26 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'] , dayfirst=True)

def solve():
    cd = df.loc[df['hours'] < 2]
    print(len(cd))

solve()