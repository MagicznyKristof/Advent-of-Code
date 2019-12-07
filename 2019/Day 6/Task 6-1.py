import networkx as nx

graph = nx.DiGraph()

list_of_orbits = [pair.split(')') for pair in
	open("Task 6-1.txt").read().strip().split('\n')]
	
for pair in list_of_orbits:
	graph.add_edge(*pair)

paths = nx.transitive_closure(graph)

print(paths.size( ))
