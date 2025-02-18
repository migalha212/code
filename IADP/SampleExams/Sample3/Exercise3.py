# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:19:20 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    df.drop(columns=(df.loc[:,["code","fastest_lap_speed","race"]]).columns,inplace=True)
solve()
print(df.head(3))