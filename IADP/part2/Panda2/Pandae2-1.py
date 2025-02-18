# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 07:26:06 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'], dayfirst=True)

def solve():
    df['age'] = pd.to_numeric(df['age'], errors='coerce')

    # Group by 'rank' and calculate mean and std for the 'age' column
    result = df.groupby('rank').agg(mean=('age', 'mean'), std=('age', 'std'))
    result['mean'] = result['mean'].round(2)
    result['std'] = result['std'].round(2)
    print(f'{result}')

solve()