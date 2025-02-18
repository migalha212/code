# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:10:13 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    pivot = pd.pivot_table(
        df, 
        values='Quantity',
        index='Product line', 
        aggfunc='sum', 
        margins=True, 
        margins_name='All')
    print(pivot)

solve()