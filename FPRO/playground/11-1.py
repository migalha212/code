def bubble_sort(alist: list):
    flag = True
    while flag:
        flag = False
        for i in range(len(alist)-1):
            if alist[i] > alist[i+1]:
                a = alist[i+1]
                alist[i+1] = alist[i]
                alist[i] = a
                flag = True
            
    return alist

print(bubble_sort([5,4,2.5,6]))