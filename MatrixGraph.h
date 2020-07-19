#ifndef H_MATRIXGRAPH
#define H_MATRIXGRAPH

#include "Graph.h"
#include "IAlgorithms.h"
#include <queue>
#include <map>
class MatrixGraph : public Graph, public IAlgorithms {
private:
	bool **graph;
	int vertexNumber;

public:
	MatrixGraph(int n);
	MatrixGraph() : vertexNumber(0), graph(new bool*[0]) {
		graph = new bool*[0];
	}
	~MatrixGraph();
	MatrixGraph(const MatrixGraph &temp) {
		vertexNumber = temp.vertexNumber;
		graph = new bool*[temp.vertexNumber];
		for (int i = 0; i < temp.vertexNumber; ++i) {
			graph[i] = new bool[temp.vertexNumber];
			for (int j = 0; j < temp.vertexNumber; ++j)
				graph[i][j] = temp.graph[i][j];
		}
	}

	int CountVertex() const {
		return vertexNumber;
	}

	bool** get_graph() const {
		return graph;
	}

	void AddV(int v);
	bool DeleteVertex(int v);
	void ToListbox(System::Windows::Forms::ListBox^ listbox);
	void Clear();
	void AddArc(int from, int to);
	bool DeleteArc(int from, int to);
	bool HasArc(int from, int to) const;

	System::String^ getView();
	System::String^ getGraph();

	void printOriginalGraph(Graphics ^gr, SolidBrush ^brush, Pen^ penGraph, Pen^ penWhite, map<int, Dot> &my_map, int width, int height, int radius);
	System::String^ to_string();

};
#endif