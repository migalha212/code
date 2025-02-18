# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:21:09 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    p = df['fastest_lap_speed'].idxmax()
    print(df.loc[p:p,["name",'race','fastest_lap_speed']].round(1))
solve()