# -*- coding: utf-8 -*-
"""
Created on Sat Nov 23 11:22:54 2024

@author: miguel P.
"""

fname = str(input('Filename:'))
fhandle = open(fname,'r')
nameCount = 0
nameList = []
for line in fhandle:
    nameList.append(line)
    nameCount = nameCount + 1
    
nameList.sort()

for name in nameList:
    print(name)
    
print(f'Count of names: {nameCount}')