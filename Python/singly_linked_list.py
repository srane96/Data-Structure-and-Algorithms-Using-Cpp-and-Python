#######################################################################
# Author: Siddhesh Rane
# Github: srane96
# Aim: Create singly linked list. Implement various functionalities 
#      such as addition and deletion of nodes.
#######################################################################

class Node:
    def __init__(self,val,nxt=None):
        self.value = val
        self.next = nxt
    def get_next(self):
        return self.next
    def get_value(self):
        return self.value
        
class LinkedList:
    def __init__(self,root_node=None):
        self.head = root_node
        self.size = 1
    def set_head(self,node):
        self.head = node
    def get_head(self):
        return self.head
    def get_size(self):
        return self.size
    def add_begin(self,val):
        node = Node(val)
        node.next = self.head
        self.head = node
        self.size += 1
    def add_end(self,val):
        node = Node(val)
        last_node = self.head
        while last_node.next is not None:
            last_node = last_node.next
        last_node.next = node
        self.size += 1
    def remove(self,val):
        prev_node = None
        curr_node = self.head
        while curr_node.value is not val and curr_node is not None:
            prev_node = curr_node
            curr_node = curr_node.next
        if curr_node is None:
            print("This value does not exist in the list")
        else:
            if prev_node is not None:
                # it means any middle element is removed
                prev_node.next= curr_node.next
            else:
                # it means first element is removed
                self.head = curr_node.next
            self.size -= 1
    def print_list(self):
        print("Printing list:")
        curr_node = self.head
        while curr_node is not None:
            print(curr_node.value)
            curr_node = curr_node.next
        print("list size: ",self.size)

# create a linked list of various nodes
mon = Node('Monday')
l_list = LinkedList(mon)
l_list.print_list()

# add new node
l_list.add_end('Wednesday')
l_list.print_list()

# remove wed and add tuesday
l_list.remove('Wednesday')
l_list.add_end('Tuesday')
l_list.print_list()

# remove monday
l_list.remove('Monday')
l_list.print_list()

# add other days and add monday also
l_list.add_end('Wednesday')
l_list.add_end('Thursday')
l_list.add_end('Friday')
l_list.add_end('Saturday')
l_list.add_end('Sunday')
l_list.add_begin('Monday')
l_list.print_list()

