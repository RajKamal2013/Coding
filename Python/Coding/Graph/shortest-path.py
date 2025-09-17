import heapq

from Coding.Graph.graph import Graph


class GraphShortestPath(Graph):

    def shortest_path(self, start, end):
        """
        Calculate the shortest path from a starting node to an ending node in a sparse graph
        with potentially 10000s of nodes. Must run under 0.5 second and find the shortest distance between two nodes.

        Parameters:
        start: The starting node.
        end: The ending node.

        Returns:
        A tuple containing the total distance of the shortest path and a list of nodes representing that path.
        """
        dist = None
        path = None

        # Priority queue to store (cost, vertex, path)
        queue = [(0, start, [])]
        visited = set()
        min_cost = {start: 0}

        while queue:
            (cost, current_vertex, path) = heapq.heappop(queue)

            if current_vertex in visited:
                continue

            visited.add(current_vertex)
            path = path + [current_vertex]

            # Early termination if we reach the end vertex
            if current_vertex == end:
                return (cost, path)

            # Iterate over all edges to find neighbors
            for adj_vertex in self.get_adjacent_vertices(current_vertex):
                if adj_vertex not in visited:
                    old_cost = min_cost.get(adj_vertex, float('inf'))
                    new_cost = cost + self._get_edge_weight(current_vertex, adj_vertex)
                    if new_cost < old_cost:
                        min_cost[adj_vertex] = new_cost
                        heapq.heappush(queue, (new_cost, adj_vertex, path))

        return (float('inf'), [])