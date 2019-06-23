"""
This implementation uses the LinkedList implementation from linked_list.py
"""
class Element(object):
    """ Element object represents each element in the linked list."""
    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next

class LinkedList(object):
    """ Linked list manages all the Element objects. """
    def __init__(self, head=None):
        self.head = head

    def print_list(self):
        """ Linked list manages all the Element objects. """
        current = self.head
        lst = []
        while current:
            lst.append(current.value)
            current = current.next
        print lst

    def append(self, new_element):
        """ Append new element to the current Linked list. """
        current_element = self.head
        if current_element:
            while current_element.next:
                current_element = current_element.next
            current_element.next = new_element
        else:
            self.head = new_element

    def append_fist(self, new_element):
        """ This is used for push operation in stack. """
        new_element.next = self.head
        self.head = new_element

    def delete_first(self):
        if self.head:
            first = self.head
            self.head = first.next
            return first
        else:
            return None

class Stack(object):
    """ Stack class used linked list in LIFO manner. """

    def __init__(self):
        self.ll = LinkedList()

    def print_stack(self):
        self.ll.print_list()

    def push(self, value):
        """ Add new value to the stack. """
        new_element = Element(value)
        self.ll.append_fist(new_element)

    def pop(self):
        """ Remove and return lates element from stack. """
        new_element = self.ll.delete_first()
        return new_element.value


# Test stack operation
s = Stack()
s.print_stack()
s.push(5)
s.push(4)
s.push(3)
s.push(2)
s.print_stack()
v1 = s.pop()
print v1
s.print_stack()
