import networkx as nx

graph = nx.DiGraph()

list_of_orbits = [pair.split(')') for pair in
	open("Task 6-1.txt").read().strip().split('\n')]
	
for pair in list_of_orbits:
	graph.add_edge(*pair)

print(nx.shortest_path_length(graph.to_undirected(), 'YOU', 'SAN') - 2)

