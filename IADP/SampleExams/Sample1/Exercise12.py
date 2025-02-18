# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 13:07:41 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    bins = [0, 20, 40, 60, 80, 100]
    labels = ['very_young', 'young', 'middle_age', 'old', 'very_old']
    df['age'] = pd.cut(df['age'], bins=bins, labels=labels, right=False)
    pd.cut
    age_counts = df['age'].value_counts().sort_index()
    print(age_counts)
solve()