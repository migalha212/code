# -*- coding: utf-8 -*-
"""
Created on Sat Nov 23 11:31:49 2024

@author: migal
"""

fname = str(input('Filename:'))
column = str(input('Column name:'))
funct = str(input('Function name:'))

fhand = open(fname,'r')
valueList = []
valueloc = 0
collums = fhand.readline().split(';')
for i in range(0,len(collums)) :
    if collums[i] == column:
        valueloc = i
        
for line in fhand:
    values = line.split(';')
    valueList.append(int(values[valueloc]))
    
valueList.sort()
res = 0
if funct == 'max':
    res = valueList[-1]
elif funct == 'min':
    res = valueList[0]
elif funct == 'sum':
    for value in valueList:
        res = res + value
        
print(funct + '(' + column + ')=' + f'{res:.2f}')