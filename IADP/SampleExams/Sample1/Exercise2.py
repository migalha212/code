# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:09:52 2025

@author: migal
"""

import numpy as np
import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    pf = df[df['salary'] >= 150000]
    age = pf['age'].agg(['min','max','median']).round(1)
    print(age)
solve()