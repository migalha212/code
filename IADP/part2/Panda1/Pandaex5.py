# -*- coding: utf-8 -*-
"""
Created on Wed Dec 18 23:53:00 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'], dayfirst=True)

def solve():
    cc = df.groupby('children')['children'].value_counts()
    print(cc.idxmax())
    
    
solve()