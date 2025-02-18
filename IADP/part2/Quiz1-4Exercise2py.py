# -*- coding: utf-8 -*-
"""
Created on Mon Dec 16 23:16:22 2024

@author: migal
"""

import time
import calendar
import datetime as dt

date = input("Date:")

date_frmt = "%Y-%m-%d %H:%M:%S"

datet = dt.datetime.strptime(date,date_frmt)

calendar.setfirstweekday(0)
print(calendar.day_name[calendar.weekday(datet.year, datet.month, datet.day)])