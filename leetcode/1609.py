def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
    if not root:
        return True
    queue = deque([root])
    i = 1
    while ((2**i)-1 < len(queue)):
        for j in range((2**(i-1))-1, (2**i)-1):
            node = queue.popleft()
            if node % 2 != i % 2:
                return False
        i += 1
    return True
    
def main():
    root = []
    

if __name__ == '__main__':
    main()
