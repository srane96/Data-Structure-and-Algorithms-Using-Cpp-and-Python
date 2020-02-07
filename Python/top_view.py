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
def topView(root):
    #Write your code here
    nodes_queue = []
    levels_dict = {}
    dist_from_root = 0
    nodes_queue.append([root, dist_from_root])
    while(not len(nodes_queue) == 0):
        curr_element = nodes_queue.pop(0)
        curr_node = curr_element[0]
        curr_distance = curr_element[1]
        if curr_distance in levels_dict.keys():
            levels_dict[curr_distance].append(curr_node)
        else:
            levels_dict[curr_distance] = [curr_node]

        # Now add next level to the queue
        if(curr_node.left):
            nodes_queue.append([curr_node.left, curr_distance-1])
        if(curr_node.right):
            nodes_queue.append([curr_node.right, curr_distance+1]) 

    # print first elements from all the levels
    answer = ""
    for l in sorted(levels_dict.keys()):
        temp = str(levels_dict[l][0].info) + " "
        answer += temp
    print(answer)




tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

topView(tree.root)
