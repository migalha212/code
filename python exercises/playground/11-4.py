from math import sqrt
def closest_pair(points:list):
    points.sort()
    def aux(p: list):
        if len(p) == 2:
            return sqrt((p[0][0] -p[1][0])**2 + (p[0][1]-p[1][1])**2)
        left = p[:len(p) //2]
        right = p[len(p) //2:]
        

print(closest_pair([(1256, 8483), (61, 2321), (9442, 4823), (1940, 700)]))