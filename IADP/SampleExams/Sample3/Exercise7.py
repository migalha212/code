# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:31:48 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    df.insert(2,"surname",df['name'].str.split(' ').str[1])
solve()
print(df.head(3))