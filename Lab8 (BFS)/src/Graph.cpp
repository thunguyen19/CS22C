/**
 * ThuMinh Nguyen
 * Graph.cpp
 * FileName
 */

#include "Graph.h"
#include <iostream>
#include <fstream>

Graph::Graph(int n) {
	edges = 0;
	vertices = n;
	for (int i = 0; i <= vertices; ++i) {
		adj.push_back(List<int>());
		color.push_back('W');
		distance.push_back(-1);
		parent.push_back(0);
	}
}

Graph::~Graph() {
}

int Graph::get_num_edges() {
	return edges;
}

int Graph::get_num_vertices() {
	return vertices;
}

bool Graph::is_empty() {
	return (vertices == 0);
}

void Graph::addEdge(int u, int v) {
	if (v == u) {
		adj[u].add_end(v);

	} else {
		adj[u].add_end(v);
		adj[v].add_end(u);

	}
}

void Graph::breadth_first_search(int source) {
	for (int i = 1; i <= get_num_vertices(); ++i) {
		color[i] = 'W';
		distance[i] = -1;
		parent[i] = 0;
	}
	Queue Q;
	color[source] = 'G';
	distance[source] = 0;
	Q.enqueue(source);
	int x = 0;
	while (!Q.is_empty()) {
		x = Q.get_front();
		Q.dequeue();
		adj[x].begin_cursor();
		while (!adj[x].off_end()) {
			int y = adj[x].get_cursor();
			if (color[y] == 'W') {
				color[y] = 'G';
				distance[y] = distance[x] + 1;
				parent[y] = x;
				Q.enqueue(y);
			}
			adj[x].move_cursor();
		}
		color[x] = 'B';
	}
}

void Graph::print_graph(ofstream& outfile) {
	for (int i = 1; i <= get_num_vertices(); ++i) {
		outfile << i << ": ";
		adj[i].print(outfile);
	}
}

void Graph::print_BFS(ofstream& outfile) {
	outfile << "v\tc\tp\td\n";
	for (int i = 1; i <= get_num_vertices(); ++i) {
		outfile << i << "\t" << color[i] << "\t" << parent[i] << "\t"
				<< distance[i] << endl;
	}
}

void Graph::print_pathHelper(int source, int destination, ofstream& outfile) {
	if (destination == source) {
		outfile << source << " ";
	} else {
		print_pathHelper(source, parent[destination], outfile);
		outfile << destination << " ";
	}
}

void Graph::print_path(int source, int destination, ofstream& outfile) {
	if (parent[destination] == 0) {
		outfile << "No path " << source << "-" << destination << " exists.\n";
	} else {
		outfile << "A shortest " << source << "-" << destination
				<< " path is: ";
		print_pathHelper(source, destination, outfile);
	}
	outfile << "\n";
}

void Graph::print_distance(int source, int destination, ofstream& output) {
	output << "The distance from " << source << " to " << destination << " is ";
	if (distance[destination] == -1) {
		output << "infinity\n";
	} else
		output << distance[destination] << endl;
}
