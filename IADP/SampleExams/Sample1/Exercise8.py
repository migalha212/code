# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 12:46:08 2025

@author: migal
"""

import pandas as pd
df = pd.read_csv('adult1.csv', sep=';',parse_dates=['birthday'])
def solve():
    birthday_counts = df['birthday'].dt.year.value_counts()
    print(birthday_counts.tail(3))
solve()