def count_zeros(f):
    def aux(alist:list):
        if len(alist) == 1 and alist[0] == 0:return 1
        if len(alist) == 1 and alist[0] == 1:return 0
        left = alist[:len(alist) // 2]
        right = alist[len(alist) // 2:]
        if 1 not in right:
            return len(right) + aux(left)
        else: return aux(right) + aux(left)
    return aux(f())
#podia ser muito mais simples
#return def count_zeros(f): list(f).count(0)