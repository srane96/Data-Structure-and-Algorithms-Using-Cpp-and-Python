###################################################################################################
# Author: Siddhesh Rane
# Github: srane96
# Aim: Create a node class with single data value and pointer to the neighbour. Then traverse it.
###################################################################################################

class months:
    def __init__(self,val=None):
        self.value = val
        self.next = None

# Define node elements with values
jan = months('January')
feb = months('February')
mch = months('March')
apr = months('April')
may = months('May')

# Link them toghter
jan.next = feb
feb.next = mch
mch.next = apr
apr.next = may

# traverse the linked node structure
init = jan
while init:
    print(init.value)
    init = init.next

