#include "GraphConvert.h"

SetGraph* GraphConvert::ConvertToSet(const MatrixGraph &srcGraph) {
	int n = srcGraph.CountVertex();
	SetGraph *destGraph = new SetGraphAlgs(n);
	for (int i = 0; i < n; i++) {
		bool *srcRow = srcGraph.get_graph()[i];
		multiset<int> &destRow = destGraph->get_graph()[i];
		for (int j = 0; j < n; j++) {
			if (srcRow[j])
				destRow.insert(j);
		}
	}
	return destGraph;
}

SetGraph* GraphConvert::ConvertToSet(const ListGraph &srcGraph) {
	int n = srcGraph.CountVertex();
	SetGraph *destGraph = new SetGraphAlgs(n);
	for (int i = 0; i < n; ++i) {
		multiset<int> &destRow = destGraph->get_graph()[i];
		list<int> &srcRow = srcGraph.get_graph()[i];
		for (int to : srcRow) {
			destRow.insert(to);
		}
	}
	return destGraph;
}

MatrixGraph* GraphConvert::ConvertToMatrix(const ListGraph &srcGraph) {
	int n = srcGraph.CountVertex();
	MatrixGraph *destGraph = new MatrixGraphAlgs(n);
	for (int i = 0; i < n; ++i) {
		list<int> &srcRow = srcGraph.get_graph()[i];
		for (int to : srcRow) {
			destGraph->AddArc(i, to);
		}
	}
	return destGraph;
}

MatrixGraph* GraphConvert::ConvertToMatrix(const SetGraph &srcGraph) {
	int n = srcGraph.CountVertex();
	MatrixGraph * destGraph = new MatrixGraphAlgs(n);
	for (int i = 0; i < n; i++) {
		multiset<int> &srcRow = srcGraph.get_graph()[i];
		for (int j = 0; j < n; ++j)
			if (find(srcRow.begin(), srcRow.end(), j) != srcRow.end())
				destGraph->AddArc(i, j);
	}
	return destGraph;
}

ListGraph* GraphConvert::ConvertToList(const SetGraph &srcGraph) {
	int n = srcGraph.CountVertex();
	ListGraph * destGraph = new ListGraphAlgs(n);
	for (int i = 0; i < n; i++) {
		multiset<int> &srcRow = srcGraph.get_graph()[i];
		list<int> &destRow = destGraph->get_graph()[i];
		for (int j = 0; j < n; ++j)
			if (find(srcRow.begin(), srcRow.end(), j) != srcRow.end())
				destRow.push_back(j);
	}
	return destGraph;
}

ListGraph* GraphConvert::ConvertToList(const MatrixGraph &srcGraph) {
	int n = srcGraph.CountVertex();
	ListGraph *destGraph = new ListGraphAlgs(n);
	for (int i = 0; i < n; i++) {
		bool *srcRow = srcGraph.get_graph()[i];
		list<int> &destRow = destGraph->get_graph()[i];
		for (int j = 0; j < n; j++) {
			if (srcRow[j])
				destRow.push_back(j);
		}
	}
	return destGraph;
}
