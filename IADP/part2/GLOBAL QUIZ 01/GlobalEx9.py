# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:43:13 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    df.columns = df.columns.str.replace(' ', '_')

solve()
print(df.loc[:,['Invoice_ID','Customer_type','Product_line','Unit_price','Tax_5%']].head(3))