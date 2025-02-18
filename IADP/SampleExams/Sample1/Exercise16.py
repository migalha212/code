# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 13:30:26 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    pf = df[((df['education'] > 15) & (df['salary'] < 35000)) | ((df['education'] < 5) & (df['salary'] >100000))]
    pf = pf.loc[:,"education":"salary"]
    print(pf)
solve()