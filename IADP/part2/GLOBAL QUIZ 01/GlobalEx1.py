# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:09:10 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    # Count the occurrences of each gender
    print(df['Gender'].value_counts(normalize=True) * 100)
    

    
solve()