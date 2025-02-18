# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 15:13:18 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    print(df.loc[[3,5,7],"name":"points"])
solve()