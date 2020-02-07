class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def vertical_levels(root):
    #Write your code here
    curr = root
    nodes_stack = []
    count = 0
    level_dict = {}
    while(curr or not len(nodes_stack) == 0):
        while(curr):
            nodes_stack.append(curr)
            curr = curr.left
            if curr:
                count -= 1
        # curr is null now
        curr = nodes_stack.pop()
        if count in level_dict.keys():
            level_dict[count].append(curr)
        else:
            level_dict[count] = [curr]
        curr = curr.right
        if curr:
            count += 1
    answer = ""
    for l in level_dict.keys():
        print("----Distance from root horizontally:",l)
        for n in level_dict[l]:
            print(n)
    print(answer)


tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

vertical_levels(tree.root)
