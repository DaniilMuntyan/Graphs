#pragma once
#ifndef H_SETGRAPH
#define H_SETGRAPH

#include "Graph.h"
#include "IAlgorithms.h"
#include <set>
#include <queue>
#include <map>
class ListGraph;
class Handler;
	
class SetGraph : public Graph, public IAlgorithms {
private:
	multiset <int> *graph;
	int vertexNumber;
public:
	SetGraph(int n) : vertexNumber(n), graph(new multiset<int> [n]) {}

	SetGraph() : vertexNumber(0), graph(new multiset<int>[0]) {}

	SetGraph(const SetGraph &setGraph) {
		vertexNumber = setGraph.CountVertex();
		graph = new multiset<int>[vertexNumber];
		for (int i = 0; i < vertexNumber; i++) {
			multiset<int> &temp = setGraph.graph[i];
			for (int to : temp) {
				graph[i].insert(to);
			}
		}
	}

	~SetGraph();

	int CountVertex() const {
		return vertexNumber;
	}

	multiset <int>* get_graph() const {
		return graph;
	}

	void AddV(int v);
	bool DeleteArc(int from, int to);
	bool DeleteVertex(int v);
	void Clear();

	void AddArc(int from, int to);
	bool HasArc(int from, int to) const;

	System::String^ getView();
	System::String^ getGraph();

	void printOriginalGraph(Graphics ^gr, SolidBrush ^brush, Pen^ penGraph, Pen^ penWhite, map<int, Dot> &my_map, int width, int height, int radius);
	void ToListbox(System::Windows::Forms::ListBox^ listbox);

};
#endif

