# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:49:58 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')


def solve():
    # Assuming df is the DataFrame containing 'City', 'Product line', and 'Total' columns
    
    # Create a pivot table to calculate the sum of 'Total' by 'City' and 'Product line'
    pivot = pd.pivot_table(df, values='Total', index='City', columns='Product line', aggfunc='sum', fill_value=0)
    
    # Find the index (City and Product line) corresponding to the maximum sum
    max_sum = pivot.max().max()  # Find the maximum sum of 'Total'
    
    # Find the row and column corresponding to the maximum sum
    max_city, max_product_line = pivot.stack().idxmax()
    
    # Print the result
    print(f"{max_city}, {max_product_line}, {round(max_sum, 2)}")

solve()