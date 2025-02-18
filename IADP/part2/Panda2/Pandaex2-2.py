# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 07:58:43 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'] ,dayfirst=True)

def solve():
    simpe = df.iloc[:,[0,5,9]]
    simpe = simpe.loc[simpe['class'].isin(['pilates'])]
    simpe = simpe.pivot_table(index='name',columns='class',values='hours')
    
    print(simpe['pilates'].idxmax())

solve()