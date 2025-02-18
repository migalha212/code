# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 00:04:10 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'] , dayfirst=True)

def solve():
    cc = df.loc[(df['age'] > 50) &(df['sex'].isin(['F']))]
    cd = cc.loc[cc['status'].isin(['married'])]
    print(cd.iloc[:,[1,5,7,9]])
    
solve()