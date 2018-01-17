/**
 * ThuMinh Nguyen
 * CIS 22C
 * BFS.cpp
 */

#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;
/*
int main() {
	ifstream input;
	ofstream output;
	input.open("infile.txt");
	if (input.fail()) {
		cout << "Input file failed to open.\n";
		exit(-1);
	}
	output.open("outfile.txt");
	if (output.fail()) {
		cout << "Output file failed to open.\n";
		exit(-1);
	}

	int numVertices = 0;
	input >> numVertices;
	Graph G(numVertices);

	int vertice;
	int value;

	//loop to read in file for the first part
	do {
		input >> vertice;
		input >> value;
		if (vertice == 0 && value == 0) {
			break;
		}
		G.addEdge(vertice, value);
	} while (!input.eof());
	G.print_graph(output);

	// loop to read in file for the second part
	do {
		input >> vertice;
		input >> value;
		if (vertice == 0 && value == 0) {
			break;
		}
		G.breadth_first_search(vertice);
		G.print_distance(vertice, value, output);
		G.print_path(vertice, value, output);
	} while (!input.eof());

	input.close();
	output.close();
	return 0;
}
/* TestRun-File Output 1
1: 2 3
2: 1 4 5 6
3: 1 4
4: 2 3 5
5: 2 4 6
6: 2 5
The distance from 1 to 5 is 2
A shortest 1-5 path is: 1 2 5
The distance from 3 to 6 is 3
A shortest 3-6 path is: 3 1 2 6
The distance from 2 to 3 is 2
A shortest 2-3 path is: 2 1 3
The distance from 4 to 4 is 0
No path 4-4 exists.
*/
/*
1: 4 5
2: 3 6
3: 2 7
4: 1 5
5: 1 4
6: 2 7
7: 3 6
The distance from 2 to 7 is 2
A shortest 2-7 path is: 2 3 7
The distance from 3 to 6 is 2
A shortest 3-6 path is: 3 2 6
The distance from 1 to 7 is infinity
No path 1-7 exists.
*/
