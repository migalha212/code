# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:41:03 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')


def solve():
    # Assuming df is the DataFrame containing the 'City', 'Payment', and 'Total' columns
    
    # Create a pivot table to calculate the sum of 'Total' by 'City' and 'Payment'
    pivot = pd.pivot_table(df,
                           values='Total', 
                           index='City',
                           columns='Payment',
                           aggfunc='sum', 
                           fill_value=0)
    
    # Round the result to two decimal places
    pivot_rounded = pivot.round(2)
    
    # Print the result
    print(pivot_rounded)

solve()