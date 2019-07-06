""" Binary search tree is similar to binary tree, except it has children nodes
ordered in certain way. ie. Left child is smaller than parent and right child
is bigger than parent."""
class Node(object):
    """ Node class represents every element of the tree. Each element has two
    children (left and right) nodes. """
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree(object):
    """ BinaryTree class uses Node class to create its leaves. """
    def __init__(self, root):
        """ Initiate tree with root of object type Node. """
        self.root = Node(root)

    def insert(self, new_val):
        current = self.root
        # repeat until you find a right empty place
        while current:
            if new_val > current.value:
                # see right
                if current.right:
                    current = current.right
                else:
                    current.right = Node(new_val)
                    break
            else:
                # see left
                if current.left:
                    current = current.left
                else:
                    current.left = Node(new_val)
                    break

    def search(self, root, find_val):
        """ Search the node with the given value. If value is present then
        return true otherwise return false. """
        current = root
        if current:
            if current.value == find_val:
                return True
            elif current.value > find_val:
                return self.search(current.left,find_val)
            else:
                return self.search(current.right,find_val)
        else:
            return False

    def print_tree(self, root):
        """ Print all the values in the tree. """
        current = root
        if current:
            print(current.value)
            if current.left:
                self.print_tree(current.left)
            if current.right:
                self.print_tree(current.right)

# Create a BinarySearchTree
tree = BinarySearchTree(2)
tree.insert(1)
tree.insert(3)
tree.insert(4)

# Should be TRUE
print(tree.search(tree.root, 1))
print(tree.search(tree.root, 2))
print(tree.search(tree.root, 3))

# should be False
print(tree.search(tree.root, 5))

# test print_tree
tree.print_tree(tree.root)
