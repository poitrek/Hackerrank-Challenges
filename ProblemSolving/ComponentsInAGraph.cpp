#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>


// Returns {graph_size, vector_of_graph_edges}
std::pair<int, std::vector<std::pair<int, int>>> ReadInput() {
	int n_edges;
	std::cin >> n_edges;
	std::vector<std::pair<int, int>> edges (n_edges);
	int graph_size = 0;
	for (int i = 0; i < n_edges; i++) {
		int first, second;
		std::cin >> first >> second;
		// Correction at the node index (should start from 0 instead of 1)
		edges[i] = {first-1, second-1};
		// Use the indexes to tell the size of the graph
		graph_size = std::max({graph_size, first, second});
	}
	return {graph_size, edges};
}

// Unlabeled node (neighbors only)
struct Node
{
	std::vector<Node *> neighbors;
	bool visited = false;
};

// Unlabeled graph (just nodes and edges)
class Graph
{
public:
	std::vector<Node> nodes;
	Graph(int size, std::vector<std::pair<int, int>> edges)
	{
		nodes = std::vector<Node>(size);
		for (std::pair<int, int> edge : edges)
		{
			nodes[edge.first].neighbors.push_back(&nodes[edge.second]);
			nodes[edge.second].neighbors.push_back(&nodes[edge.first]);
		}
	}

	// Count component size using BFS, with index of the starting node
	int BFSCount(int startingNodeIdx=0)
	{
		return BFSCount(&nodes[startingNodeIdx]);
	}

	// Count component size using BFS, with pointer to the starting node
	int BFSCount(Node *n)
	{
		// std::set<Node *> seen = {n};
		int n_visited = 0;
		std::deque<Node *> visit_queue = {n};
		while (!visit_queue.empty())
		{
			Node *n = visit_queue.front();
			visit_queue.pop_front();
			for (Node *ne : n->neighbors)
			{
				// if the node hasn't been seen yet
				if (!ne->visited)
				{
					ne->visited = true;
					n_visited++;
					visit_queue.push_back(ne);
				}
			}
		}
		return n_visited;
	}
};

std::pair<int, int> MaxMinComponents(Graph &g)
{
	int max_size = 0, min_size = 100000;
	// Numer of untraversed nodes
	// int n_untraversed = g.nodes.size();
	for (Node &n : g.nodes)
	{
		// Ignore nodes which have no neighbors
		if (n.neighbors.size() > 0 && !n.visited) {
			int component_size = g.BFSCount(&n);
			// Update max & min size
			if (component_size > max_size)
				max_size = component_size;
			if (component_size < min_size)
				min_size = component_size;
		}
	}
	return {max_size, min_size};
}

int main()
{
	auto graph_data = ReadInput();
	Graph g(graph_data.first, graph_data.second);
	std::pair<int, int> max_min_comp = MaxMinComponents(g);
	std::cout << max_min_comp.second << " " << max_min_comp.first << std::endl;
	return 0;
}
