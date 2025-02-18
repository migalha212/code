# -*- coding: utf-8 -*-
"""
Created on Wed Dec 18 23:44:38 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'], dayfirst=True)

def solve():
    pf = df
    print(f'{pf['age'].std():.f}')
    
    
solve()

