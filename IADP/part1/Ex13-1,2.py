# -*- coding: utf-8 -*-
"""
Created on Sat Nov 23 11:15:33 2024

@author: migal
"""

def gcd(a,b):
    small = min(a,b)
    for i in range(1,small+1):
        if(a % i == 0) and (b % i == 0):
            gcd = i
    return gcd

def fact(num):
    res = 1
    for i in range(1,num + 1):
        res = res * i
    return res

