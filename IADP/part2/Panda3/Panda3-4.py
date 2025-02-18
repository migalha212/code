# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 08:23:06 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'], dayfirst=True)

def solve(name):
    
    reference_date = pd.to_datetime('2022-01-01')
    
    customer = df[df['name'] == name]
    
    registration_date = pd.to_datetime(customer['date'].iloc[0])
    
    days_diff = (reference_date - registration_date).days
    print(str(days_diff) + " days")

solve('Marisa Martins')