# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:02:57 2025

@author: migal
"""
import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])

def solve():
    pf = df
    pf = pf.iloc[[1,4,6],6:11]
    print(pf)
solve()
