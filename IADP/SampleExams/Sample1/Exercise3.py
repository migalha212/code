# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:15:53 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
print(df.shape)

def solve():
    global df
    df = df[(df['sex'] != 'Male') | (df['age'] < 45)]

solve()
print(df.shape)