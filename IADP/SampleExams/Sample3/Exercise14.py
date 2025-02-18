# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 16:01:40 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('f1_1.csv',encoding='utf-8',parse_dates=['dob','date'])
def solve():
    b = [0,40,80,120,160]
    l = ["novice","senior","expert","star"]
    p = df['name'].value_counts()
    c = pd.cut(p,bins=b,labels=l,right=False)
    c.name = None
    print(c.value_counts())
    
    
solve()