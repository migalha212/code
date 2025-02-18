# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:27:44 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    global df
    mina = df['age'].min()
    pf = df[df['age'] == mina]
    av = pf['salary'].mean().round(1)
    
    print(f'Minimum age: {mina}')
    print(f'Average salary for people with that age: {av}')
solve()