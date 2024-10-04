def time_diff(time1, time2):
    if time1 > time2:
       if time1[1] - time2[1] < 0:
           return (time1[0] - time2[0] - 1, 60 + time1[1] - time2[1])
       else:
           return (time1[0] - time2[0], time1[1] - time2[1])
        
    else:
       if time2[1] - time1[1] < 0:
           return (time2[0] - time1[0] - 1, 60 +time2[1] - time1[1])
       else:
           return (time2[0] - time1[0], time2[1] - time1[1])
       
