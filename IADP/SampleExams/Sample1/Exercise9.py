# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:52:54 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    df.insert(11,'retirementdate',df['birthday'] + pd.DateOffset(years=66) )
solve()
print(df.loc[:,'salary':'birthday'].head(3))