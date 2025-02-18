# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 08:23:05 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'], dayfirst=True)

def solve(old_cat,new_cat):
    df['rank'] = df['rank'].replace(old_cat, new_cat)
    
    # Convert the 'rank' column to the category data type
    df['rank'] = df['rank'].astype('category')
    
solve('fair', 'poor')

print(pd.unique(df['rank']))