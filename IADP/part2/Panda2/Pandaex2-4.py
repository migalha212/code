# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 08:04:17 2024

@author: migal
"""

import pandas as pd
df = pd.read_csv('gym2_q1.csv', sep = ";", index_col = 'id', parse_dates = ['date'], dayfirst=True)

def solve():

    df['date'] = pd.to_datetime(df['date'])

    # Filter for customers registered after 2014
    filtered_df = df[df['date'] > '2014-12-31']

    # Create a pivot table with the number of customers by status and sex
    result = pd.pivot_table(
        filtered_df,
        index='status',
        columns='sex',
        values='date',
        aggfunc='count'
    )
    print(result)

solve()

