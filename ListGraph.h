#pragma once
#ifndef H_LISTGRAPH
#define H_LISTGRAPH

#include "Graph.h"
#include "Dot.h"
#include "IAlgorithms.h"
#include <list>
#include <vector>
#include <queue>
#include <map>
class ListGraph : public Graph, public IAlgorithms {
private:
	list<int> *graph;
	int vertexNumber;

public:
	ListGraph(const ListGraph &listGraph) /*: vertexNumber(listGraph.vertexNumber), graph(listGraph.graph) */{
		vertexNumber = listGraph.CountVertex();
		graph = new list<int>[vertexNumber];
		for (int i = 0; i < vertexNumber; i++) {
			list<int> &temp = listGraph.graph[i];
			for (int to : temp) {
				graph[i].push_back(to);
			}
		}
	}
	ListGraph(int n) : vertexNumber(n), graph(new list<int>[n]) {}
	ListGraph() : vertexNumber(0), graph(new list<int>[0]) {}
	~ListGraph() {
		delete graph;
	}

	int CountVertex() const {
		return vertexNumber;
	}
	list<int>* get_graph() const {
		return graph;
	}

	void AddV(int v);
	void AddArc(int from, int to);
	bool DeleteArc(int from, int to);
	bool DeleteVertex(int v);
	void ToListbox(System::Windows::Forms::ListBox^ listbox);
	void Clear();
	bool HasArc(int from, int to) const;

	System::String^ getView();
	System::String^ getGraph();

	void printOriginalGraph(Graphics ^gr, SolidBrush ^brush, Pen^ penGraph, Pen^ penWhite, map<int, Dot> &my_map, int width, int height, int radius);
	System::String^ to_string();
};
#endif