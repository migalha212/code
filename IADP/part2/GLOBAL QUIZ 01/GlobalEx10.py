# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:44:53 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    df['c'] = 1
    d = pd.pivot_table(
        df,
        values='c',
        columns='Customer type',
        index='City',
        aggfunc='sum',
        margins=True,
        margins_name='All',
        fill_value=0)
    print(d)

solve()