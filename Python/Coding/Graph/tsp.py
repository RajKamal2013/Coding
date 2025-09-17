import graph

# GRADED CELL 4 - Do NOT delete it, do NOT place your solution anywhere else. You can create new cells and work from there, but in the end add your solution in this cell.
def nearest_neighbor_tsp(graph, start_vertex):
    """Solve the TSP using a simple Nearest Neighbor heuristic."""
    num_vertices = len(graph.graph)
    visited = set()
    tour = [start_vertex]
    visited.add(start_vertex)
    current_vertex = start_vertex

    while len(visited) < num_vertices:
        next_vertex = min(
            (v for v in graph.get_adjacent_vertices(current_vertex) if v not in visited),
            key=lambda v: graph._get_edge_weight(current_vertex, v),
            default=None
        )
        if next_vertex is None:
            break
        tour.append(next_vertex)
        visited.add(next_vertex)
        current_vertex = next_vertex

    return tour


def genetic_algorithm_tsp(graph, start_vertex, population_size=50, generations=50, mutation_rate=0.02):
    """Solve the TSP using a Genetic Algorithm, starting at a specified vertex."""
    num_vertices = len(graph.graph)

    def evaluate_population(population):
        return [(individual, graph.tour_length(individual)) for individual in population]

    # Initialize population
    population = [create_individual(num_vertices, start_vertex) for _ in range(population_size)]
    best_individual = min(population, key=lambda ind: graph.tour_length(ind))
    best_length = graph.tour_length(best_individual)

    for generation in range(generations):
        # Evaluate population
        population_with_lengths = evaluate_population(population)

        # Sort by fitness (tour length)
        population_with_lengths.sort(key=lambda x: x[1])
        population = [ind for ind, _ in population_with_lengths]

        # Select the best individuals for crossover
        new_population = population[:population_size // 2]

        # Generate new individuals through crossover and mutation
        while len(new_population) < population_size:
            parent1, parent2 = random.sample(population[:population_size // 2], 2)
            child = crossover(parent1, parent2, start_vertex)
            mutate(child, mutation_rate)
            new_population.append(child)

        population = new_population
        current_best = min(population, key=lambda ind: graph.tour_length(ind))
        current_length = graph.tour_length(current_best)
        if current_length < best_length:
            best_individual = current_best
            best_length = current_length

    return best_individual, best_length


def genetic_algorithm_tsp2(graph, start_vertex, population_size=10, generations=10, mutation_rate=0.02):
    """Solve the TSP using a Genetic Algorithm, starting at a specified vertex."""
    num_vertices = len(graph.graph)

    def evaluate_population(population):
        return [(individual, graph.tour_length(individual)) for individual in population]

    # Initialize population with nearest neighbor tours
    population = [nearest_neighbor_tsp(graph, start_vertex) for _ in range(population_size)]
    best_individual = min(population, key=lambda ind: graph.tour_length(ind))
    best_length = graph.tour_length(best_individual)

    for generation in range(generations):
        # Evaluate population
        population_with_lengths = evaluate_population(population)

        # Sort by fitness (tour length)
        population_with_lengths.sort(key=lambda x: x[1])
        population = [ind for ind, _ in population_with_lengths]

        # Select the best individuals for crossover
        new_population = population[:population_size // 2]

        # Generate new individuals through crossover and mutation
        while len(new_population) < population_size:
            parent1, parent2 = random.sample(population[:population_size // 2], 2)
            child = crossover(parent1, parent2, start_vertex)
            mutate(child, mutation_rate)
            new_population.append(child)

        population = new_population
        current_best = min(population, key=lambda ind: graph.tour_length(ind))
        current_length = graph.tour_length(current_best)
        if current_length < best_length:
            best_individual = current_best
            best_length = current_length

    return best_individual, best_length


def nearest_neighbor_tsp(graph, start_vertex):
    """Solve the TSP using a simple Nearest Neighbor heuristic."""
    num_vertices = len(graph.graph)
    visited = set()
    tour = [start_vertex]
    visited.add(start_vertex)
    current_vertex = start_vertex

    while len(visited) < num_vertices:
        next_vertex = min(
            (v for v in graph.get_adjacent_vertices(current_vertex) if v not in visited),
            key=lambda v: graph._get_edge_weight(current_vertex, v),
            default=None
        )
        if next_vertex is None:
            break
        tour.append(next_vertex)
        visited.add(next_vertex)
        current_vertex = next_vertex

    return tour


class GraphTSPMediumGraph(Graph):

    def two_opt_swap(self, tour, i, k):
        """
        Perform a 2-opt swap by reversing the segment between indices i and k.

        Parameters:
        - tour: The current tour.
        - i: The start index of the segment to reverse.
        - k: The end index of the segment to reverse.

        Returns:
        - A new tour with the specified segment reversed.
        """
        new_tour = tour[:i] + tour[i:k + 1][::-1] + tour[k + 1:]
        return new_tour

    def two_opt(self, tour, max_iterations=100):
        """
        Improve a tour using the 2-opt algorithm.

        Parameters:
        - graph (Graph): The graph representing the cities and distances.
        - tour: The initial tour.

        Returns:
        - An improved tour.
        """
        best_tour = tour
        best_length = self.tour_length(best_tour)
        iteration = 0

        while iteration < max_iterations:
            improved = False
            for i in range(1, len(best_tour) - 2):
                for k in range(i + 1, len(best_tour) - 1):
                    new_tour = best_tour[:i] + best_tour[i:k + 1][::-1] + best_tour[k + 1:]
                    new_length = self.tour_length(new_tour)
                    if new_length < best_length:
                        best_tour = new_tour
                        best_length = new_length
                        improved = True
                        break  # Exit inner loop early
                if improved:
                    break  # Exit outer loop early
            if not improved:
                break  # Exit if no improvement found
            iteration += 1

        return best_tour

    def simulated_annealing(self, initial_tour, initial_temp=500, cooling_rate=0.995, min_temp=1):
        def swap_two_cities(tour):
            new_tour = tour[:]
            i, j = random.sample(range(1, len(tour) - 1), 2)
            new_tour[i], new_tour[j] = new_tour[j], new_tour[i]
            return new_tour

        current_tour = initial_tour
        current_length = self.tour_length(current_tour)
        best_tour = current_tour
        best_length = current_length
        temp = initial_temp

        while temp > min_temp:
            new_tour = swap_two_cities(current_tour)
            new_length = self.tour_length(new_tour)

            if new_length < current_length or random.random() < math.exp((current_length - new_length) / temp):
                current_tour = new_tour
                current_length = new_length

                if new_length < best_length:
                    best_tour = new_tour
                    best_length = new_length

            temp *= cooling_rate

        return best_tour, best_length

    def greedy_tour(self, cluster_nodes, start):
        unvisited = set(cluster_nodes)
        unvisited.remove(start)
        tour = [start]
        current = start

        while unvisited:
            next_city = min(unvisited, key=lambda city: self._get_edge_weight(current, city))
            tour.append(next_city)
            unvisited.remove(next_city)
            current = next_city

        return tour

    def cluster_and_solve_with_start(self, start, num_clusters=10):
        nodes = list(self.graph.keys())
        node_indices = {node: i for i, node in enumerate(nodes)}

        # Generate random positions for clustering (or use actual coordinates if available)
        positions = np.random.rand(len(nodes), 2)

        # Cluster nodes
        kmeans = KMeans(n_clusters=num_clusters, random_state=42).fit(positions)
        labels = kmeans.labels_

        cluster_tours = []
        for cluster_id in range(num_clusters):
            cluster_nodes = [nodes[i] for i in range(len(nodes)) if labels[i] == cluster_id]
            if start in cluster_nodes:
                tour = self.greedy_tour(cluster_nodes, start)
            else:
                tour = self.greedy_tour(cluster_nodes, cluster_nodes[0])
            cluster_tours.append(tour)

        # Connect clusters ensuring the start vertex is the first
        full_tour = [start]
        visited_clusters = set()
        current_cluster = next(cluster_id for cluster_id, tour in enumerate(cluster_tours) if start in tour)

        while len(visited_clusters) < num_clusters:
            visited_clusters.add(current_cluster)
            cluster_tour = cluster_tours[current_cluster]
            full_tour.extend(cluster_tour[1:])  # Add cluster tour excluding the start node

            # Find the next closest cluster
            last_node = full_tour[-1]
            min_distance = float('inf')
            next_cluster = None
            for cluster_id, tour in enumerate(cluster_tours):
                if cluster_id not in visited_clusters:
                    distance = self._get_edge_weight(last_node, tour[0])
                    if distance < min_distance:
                        min_distance = distance
                        next_cluster = cluster_id

            if next_cluster is not None:
                current_cluster = next_cluster

        return full_tour

    def lin_kernighan_tsp(self, start_vertex):
        """
        Solve the TSP using a simplified version of the Lin-Kernighan heuristic.

        Parameters:
        - graph: An instance of the Graph class.
        - start_vertex: The starting vertex for the tour.

        Returns:
        - A tuple containing the tour and its total length.
        """
        # Initialize tour with a simple nearest neighbor approach
        tour = nearest_neighbor_tsp(self, start_vertex)
        best_tour = tour
        best_length = self.tour_length(best_tour[:-1])

        # Perform k-opt moves dynamically
        improved = True
        while improved:
            improved = False
            for k in range(2, len(tour) // 2):  # Dynamically decide k
                for i in range(len(tour) - k):
                    for j in range(i + k, len(tour)):
                        # Perform a k-opt move
                        new_tour = self.k_opt_swap(tour, i, j, k)
                        new_length = self.tour_length(new_tour[:-1])
                        if new_length < best_length:
                            best_tour = new_tour
                            best_length = new_length
                            improved = True
                            break
                    if improved:
                        break
                if improved:
                    break

        return best_tour, best_length

    def k_opt_swap(self, tour, i, j, k):
        """
        Perform a k-opt swap by rearranging the tour segment between indices i and j.

        This function is a placeholder for a more complex k-opt swap logic.
        """
        # For simplicity, perform a reverse on a segment as in 2-opt
        return tour[:i] + tour[i:j + 1][::-1] + tour[j + 1:]

    def tsp_medium_graph(self, start):
        """
        Solve the Travelling Salesman Problem for a medium (~300 node) complete graph starting from a specified node.
        Expected to perform better than tsp_large_graph. Must run under 1.5 seconds.

        Parameters:
        start: The starting node.

        Returns:
        A tuple containing the total distance of the tour and a list of nodes representing the tour path.
        """
        # Your code here
        dist = None
        path = None
        # initial_tour = nearest_neighbor_tsp(self, start)
        # tour = self.two_opt(initial_tour, max_iterations=50)
        # tour_length = self.tour_length(improved_tour)
        # tour, tour_length = self.simulated_annealing(initial_tour)
        # tour = self.cluster_and_solve_with_start(start)
        # tour_length = self.tour_length(tour)
        # Your code here
        # tour, tour_length = self.lin_kernighan_tsp(start)
        # tour, tour_length = genetic_algorithm_tsp(self, start)
        return tour, tour_length