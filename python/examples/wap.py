# path = input("Enter filepath of chat: ")


def main():
    path = "/home/lvalhalla/Downloads/hoyy.txt"
    mes_count(path)


def mes_count(path):
    fin = open(path, "r")
    name = [    ]
    count = [    ]
    msize = []
    i=0
    for mline in fin:
        i+=1
        check = 0
        line = mline.split(" ")
        #print(line)
        if len(line) > 4:
            mlen = 0
            for i in range(5, len(line)):
                mlen+= len(line[i])
            if len(line[4].split(':')) == 2:
                for i in range(len(name)):
                    try:
                        if line[4] == name[i]:
                            count[i] = count[i] + 1
                            check = 1
                            break
                    except IndexError:
                        continue
                if check ==0:
                    name.append(line[4])
                    count.append(1)

        #print((i, name, count, ' : '))
       # a = input()
        
    fin.close()

    for i in range(len(name)):
        print(name[i], count[i])


if __name__ == "__main__":
    main()
