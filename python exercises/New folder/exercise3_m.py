def total_distance(dist, cities):
    if len(cities) == 1 or len(cities) == 0: return 0

    a = 0    
    def dis(dist,cities,a):
        if len(cities) == 1: return a
        if (cities[0],cities[1]) in dist.keys():
           a += dist[(cities[0],cities[1])]

           return dis(dist,cities[1:],a)
        if (cities[1],cities[0]) in dist.keys():
            a += dist[(cities[1],cities[0])] 

            return dis(dist,cities[1:],a)
        return -1
    
    dista = dis(dist,cities,a)


    return dista




