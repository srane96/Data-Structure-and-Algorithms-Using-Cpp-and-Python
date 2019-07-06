""" Binary tree is a tree structure in which each node has two children. """
class Node(object):
    """ Node class represents every element of the tree. Each element has two
    children (left and right) nodes. """
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree(object):
    """ BinaryTree class uses Node class to create its leaves. """
    def __init__(self, root):
        """ Initiate tree with root of object type Node. """
        self.root = Node(root)

    def search(self, root, find_val):
        """ Search the node with the given value. If value is present then
        return true otherwise return false. """
        if root:
            if root.value == find_val:
                return True
            else:
                return self.search(root.left, find_val) or self.search(root.right, find_val)
        else:
            return False

    def print_tree(self, root):
        """ Print the tree in pre-order mannner. """
        current = root
        if current:
            print(current.value)
            if current.left:
                self.print_tree(current.left)
            if current.right:
                self.print_tree(current.right)
# Create binary tree
tree = BinaryTree(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)
tree.root.right.left = Node(6)
tree.root.right.right = Node(7)

# Search test
# Should be True
print tree.search(tree.root, 4)
# Should be False
print tree.search(tree.root, 6)
print tree.print_tree(tree.root)
