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
        """ Print values of the linkedList elements. """
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

    def get_position(self, position):
        """ Get element from a perticular position. Position starts from 0.
            Return None if no element is present at the given position. """
        count = 0
        current = self.head
        if position < 0:
            return None
        while current and count <= position:
            if count == position:
                return current
            else:
                current = current.next
                count += 1
        return None

    def insert(self, new_element, position):
        """ Insert a new element at the given position. """
        if position < 0:
            print("Invalid position")
            return None
        if position == 0:
            new_element.next = self.head
            self.head = new_element
        else:
            count = 0
            current_element = self.head
            while current_element and count <= position - 1:
                if count == position - 1:
                    new_element.next = current_element.next
                    current_element.next = new_element
                count += 1
                current_element = current_element.next

    def delete(self, value):
        """ Delement element with given value"""
        previous = None
        current = self.head
        while current.next and not current.value == value:
            previous = current
            current = current.next
        if current.value == value:
            if previous:
                previous.next = current.next
            else:
                self.head = current.next

# Test DS
# initialize Elements
e1 = Element(1)
e2 = Element(2)
e3 = Element(3)
e4 = Element(4)

# Create a LinkedList
ll = LinkedList(e1)
ll.append(e2)
ll.append(e3)
ll.append(e4)
ll.print_list()

# get_position test
print ll.get_position(2).value

e5 = Element(5)
# insert test
ll.insert(e5,3)
ll.print_list()
print ll.get_position(3).value

# delete test
ll.delete(4)
ll.print_list()
print ll.get_position(0).value
print ll.get_position(1).value
