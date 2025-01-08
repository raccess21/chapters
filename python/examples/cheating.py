from itertools import permutations as p
from itertools import combinations as c

def main():
    ...
    
def lister(text, num):
    return [text for _ in range(num)]
    
def seq(lst, length):
    sa = set()
    for l in c(lst, length):
        sa.add(l)
    return sa
    
def alphabets(words):
    dct = {t:i+1 for i, t in enumerate("abcdefghijklmnopqrstuvwxyz")}
    for word in words:
        for w in word:
            print(f"{w}:{dct[w]}\t", end='') 
        print()
        
        

if __name__ == '__main__':
    main()