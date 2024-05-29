import dis

def looper(n):
    lst = []
    for i in range(n):
        lst.append(n)
    return lst
    

def compre(n):
    return [i for i in range(n)]
    
dis.dis(compre)
dis.dis(looper)
