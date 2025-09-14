import json
import random

import Coding.Graph
from Coding.Graph.graph import Graph


def generate_graph(graph, nodes, edges=None, complete=False, weight_bounds=(1, 600), seed=None):
    """
    Generates a graph with specified parameters, allowing for both complete and incomplete graphs.

    This function creates a graph with a specified number of nodes and edges, with options for creating a complete graph, and for specifying the weight bounds of the edges. It uses the Graphs class to create and manipulate the graph.

    Parameters:
    - graph (one of the graph calsses for each exercise): The graph class to generate the test graph.
    - nodes (int): The number of nodes in the graph. Must be a positive integer.
    - edges (int, optional): The number of edges to add for each node in the graph. This parameter is ignored if `complete` is set to True. Defaults to None.
    - complete (bool, optional): If set to True, generates a complete graph where every pair of distinct vertices is connected by a unique edge. Defaults to False.
    - weight_bounds (tuple, optional): A tuple specifying the lower and upper bounds (inclusive) for the random weights of the edges. Defaults to (1, 600).
    - seed (int, optional): A seed for the random number generator to ensure reproducibility. Defaults to None.

    Raises:
    - ValueError: If `edges` is not None and `complete` is set to True, since a complete graph does not require specifying the number of edges.

    Returns:
    - The graph class: An instance of the Graph class you passed in the graph parameter, representing the generated graph, with vertices labeled as integers starting from 0.

    Examples:
    - Generating a complete graph with 5 nodes:
        generate_graph(5, complete=True)

    - Generating an incomplete graph with 5 nodes and 2 edges per node:
        generate_graph(5, edges=2)

    Note:
    - The function assumes the existence of a Graph class with methods for adding vertices (`add_vertex`) and edges (`add_edge`), as well as a method for getting adjacent vertices (`get_adjacent_vertices`).
    """
    random.seed(seed)
    graph = graph()
    if edges is not None and complete:
        raise ValueError("edges must be None if complete is set to True")
    if not complete and edges > nodes:
        raise ValueError("number of edges must be less than number of nodes")

    for i in range(nodes):
        graph.add_vertex(i)
    if complete:
        for i in range(nodes):
            for j in range(i + 1, nodes):
                weight = random.randint(weight_bounds[0], weight_bounds[1])
                graph.add_edge(i, j, weight)
    else:
        for i in range(nodes):
            for _ in range(edges):
                j = random.randint(0, nodes - 1)
                while (j == i or j in graph.get_adjacent_vertices(i)) and len(
                        graph.get_adjacent_vertices(i)) < nodes - 1:  # Ensure the edge is not a loop or a duplicate
                    j = random.randint(0, nodes - 1)
                weight = random.randint(weight_bounds[0], weight_bounds[1])
                if len(graph.graph[i]) < edges and len(graph.graph[j]) < edges:
                    graph.add_edge(i, j, weight)
    return graph


def main():
    graph = generate_graph(graph=Graph, nodes=10, complete=True)
    print(graph.tour_length([1, 4, 6, 8, 5]))
    print(graph._get_edge_weight(5, 8))
    for vertex in graph.graph.keys():
        print(vertex)

    print(len(graph.graph))
    print(len(graph.graph.keys()))



if __name__ == '__main__':
    main()