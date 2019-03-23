#######################################################################
# Author: Siddhesh Rane
# Github: srane96
# Aim: To implement an undirected graph DS using adjacency list.
#######################################################################

# Node class represents every node vertex on the graph
class Node:
    # Constructor for Node class
    def __init__(self,val):
        self.value = val
        self.neighbours = list()
        
    # Add new neighbour in the list of neighbours
    def add_neighbour(self,val):
        if val not in self.neighbours:
            self.neighbours.append(val)
            self.neighbours.sort()

# Graph class manages the edges and the vertices
class Graph:
    # Default constructor
    def __init__(self):
        # vertex is the dictionary of the format 
        # {node.value : Node}
        self.vertices = {}
        
    # Add vertext function adds new vertex value to list of vertices
    def add_vertex(self,node):
        # check if vertex value is of type Node and is not already
        # present in the vertices
        if isinstance(node,Node) and node.value not in self.vertices:
            self.vertices[node.value] = node
            return True
        else:
            return False
    
    # Add Edges u and v- where u and v are node values
    def add_edges(self,u,v):
        # make sure u and v is present in the vertices
        if u in self.vertices and v in self.vertices:
            for key, value in self.vertices.items():
                if key == u:
                    self.vertices[u].add_neighbour(v)
                if key == v:
                    self.vertices[v].add_neighbour(u)
            return True
        else:
            return False
        
    # print the graph in the form of node.value: [neighbours]
    def print_graph(self):
        for key, value in self.vertices.items():
            print(key,": ",str(value.neighbours))

# Testing graph structure
a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')
graph = Graph()
graph.add_vertex(a)
graph.add_vertex(b)
graph.add_vertex(c)
graph.add_vertex(d)
graph.add_vertex(e)
graph.add_vertex(f)
graph.add_edges('a','b')
graph.add_edges('a','c')
graph.add_edges('a','d')
graph.add_edges('a','e')
graph.add_edges('b','d')
graph.add_edges('c','e')
graph.add_edges('d','e')
graph.add_edges('e','f')

graph.print_graph()

