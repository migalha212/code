# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 13:16:47 2024

@author: migal
"""

import pandas as pd

df = pd.read_csv('gym_q1.csv',sep=';', parse_dates=['date'] , dayfirst=True)

def get_obs(weight):
    if weight > 80:
        return "overweight"
    elif weight <= 50:
        return "underweight"
    return "normal weight"
    
def solve():
    pf = df
    
    pf.insert(2,'observation',df['weight'])
    pf['observation'] = df['weight'].apply(get_obs)

    print(pf)
    
    

solve()