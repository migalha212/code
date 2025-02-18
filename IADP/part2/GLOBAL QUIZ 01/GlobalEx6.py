# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:32:40 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    df['QxPrice'] = df['Unit price'] * df['Quantity']
    
    # Insert the 'QxPrice' column before the 'Tax 5%' column
    tax_col_index = df.columns.get_loc('Tax 5%')  # Find the index of 'Tax 5%'
    df.insert(tax_col_index, 'QxPrice', df.pop('QxPrice')) 

solve()
print(df.loc[0:2,'Unit price':'Total'])