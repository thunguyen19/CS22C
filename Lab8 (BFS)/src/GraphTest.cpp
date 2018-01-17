/**
 * ThuMinh Nguyen
 * CIS 22C
 * GraphTest.cpp
 */

#include "Graph.h"
#include <iostream>

using namespace std;

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
	Graph test(0);
	output << "Graph should be empty. Return 1: " << test.is_empty() << endl;

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
	output << "Graph is not empty. Return 0: " << G.is_empty() << endl;

	G.print_graph(output);
	output << "Source is 1:\n";
	G.breadth_first_search(1);
	G.print_BFS(output);
	G.print_distance(1, 4, output);
	G.print_path(1, 4, output);

	output << "Source is 2:\n";
	G.breadth_first_search(2);
	G.print_BFS(output);
	G.print_distance(2, 5, output);
	G.print_path(2, 5, output);

	input.close();
	output.close();
	return 0;
}
/* infile.txt
5
1 2
1 5
2 3
2 4
3 4
4 5
5 5
0 0
*/
/* outfile.txt
Graph should be empty (true): 1
Graph is not empty. Return 0: 0
1: 2 5
2: 1 3 4
3: 2 4
4: 2 3 5
5: 1 4 5
Source is 1:
v	c	p	d
1	B	0	0
2	B	1	1
3	B	2	2
4	B	2	2
5	B	1	1
The distance from 1 to 4 is 2
A shortest 1-4 path is: 1 2 4
Source is 2:
v	c	p	d
1	B	2	1
2	B	0	0
3	B	2	1
4	B	2	1
5	B	1	2
The distance from 2 to 5 is 2
A shortest 2-5 path is: 2 1 5
*/
