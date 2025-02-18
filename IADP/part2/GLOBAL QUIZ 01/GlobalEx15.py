# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 10:01:00 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    print(df.iloc[0:3,8:11])

solve()
