i=10    #global
print(i)

def nimda():
    #print(i) not supported before local assignment
    i=20        #local i assigned
    print(i)    #local i referenced

    #global i not supported since local i exists already

nimda()
print(i)        #global i referenced

carname='volvo'     #both ' and " supported for string
print(carname)
