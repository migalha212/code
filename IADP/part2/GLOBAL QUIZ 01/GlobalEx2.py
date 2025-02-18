# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:10:16 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('supermarket1.csv', sep=';')

def solve():
    # Assuming df is the DataFrame containing a 'Total' column with invoice amounts
    
    # Define the bin edges based on the specified ranges
    bins = [0, 220, 440, 660, 880, 1100]
    
    # Define the labels for each bin (class names)
    labels = ['low', 'fair', 'good', 'very_good', 'excellent']
    
    # Categorize the 'Total' column into the defined bins
    df['Total'] = pd.cut(df['Total'], bins=bins, labels=labels, right=False)
    
    # Count the number of invoices in each class
    total_counts = df['Total_class'].value_counts()
    
    # Print the result
    print(total_counts)
    
    
solve()