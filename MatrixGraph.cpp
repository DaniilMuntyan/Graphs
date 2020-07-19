#include "MatrixGraph.h"
#include <stack>
MatrixGraph::MatrixGraph(int n) {
	graph = new bool*[vertexNumber = n];
	for (int i = 0; i < n; i++) {
		bool *row = graph[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			row[j] = false;
		}
	}
}

MatrixGraph::~MatrixGraph() {
	for (int i = 0; i < vertexNumber; i++) {
		delete graph[i];
	}
	delete graph;
}

void MatrixGraph::AddArc(int from, int to) {
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return;
	graph[from][to] = true;
}

bool MatrixGraph::DeleteArc(int from, int to)
{
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return false;
	graph[from][to] = false;
	return true;
}

void MatrixGraph::ToListbox(System::Windows::Forms::ListBox^ listbox)
{
	listbox->Items->Clear();
	listbox->Items->Add("Список побудованих ребер:");
	for (int i = 0; i < vertexNumber; ++i) {
		for (int j = i; j < vertexNumber; ++j) {
			if (graph[i][j])
				listbox->Items->Add((i + 1).ToString() + " - " + (j + 1).ToString());
		}
	}
}

void MatrixGraph::Clear()
{
	this->vertexNumber = 0;
	this->graph = new bool*[0];
}

System::String^ MatrixGraph::getView() {
	System::String^ s = "Граф представлено матрицею суміжності\n";
	for (int i = 0; i < vertexNumber; ++i) {
		if (i + 1 < 10)
			s += (i + 1).ToString() + "   | ";
		else
			s += (i + 1).ToString() + " | ";
		for (int j = 0; j < vertexNumber; ++j) {
			s += System::Convert::ToInt32(graph[i][j]).ToString() + " ";
		}
		s += "\n";
	}
	return s;
}

System::String^ MatrixGraph::getGraph()
{
	System::String^ s = vertexNumber + "\n";
	for (int i = 0; i < vertexNumber; ++i)
	{
		s += (i + 1).ToString() + ": ";
		for (int v = 0; v < vertexNumber; v++) {
			s += graph[i][v].ToString();
		}
		s += "\n";
	}
	return s;
}

void MatrixGraph::printOriginalGraph(Graphics ^gr, SolidBrush ^brush, Pen^ penGraph, Pen^ penWhite, map<int, Dot> &my_map, int width, int height, int radius)
{
	gr->Clear(Color::White);
	for (int i = 0; i < vertexNumber; ++i)
	{
		my_map[i].drawPoint(gr, brush, width, height, i + 1);
		for (int j = 0; j < vertexNumber; ++j) {
			if (graph[i][j]) {
				my_map[i].drawTo(gr, penGraph, my_map[j]);
				my_map[j].drawPoint(gr, brush, width, height, j + 1);
			}
		}
		my_map[i].drawPoint(gr, brush, width, height, i + 1);
	}
}

System::String^ MatrixGraph::to_string()
{
	System::String^ s = "";
	for (int i = 0; i < vertexNumber; ++i)
		for (int to = 0; to < vertexNumber; ++to)
			if(graph[i][to])
				s += (i).ToString() + " - " + (to).ToString() + "\n";
	return s;
}

bool MatrixGraph::HasArc(int from, int to) const {
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return false;
	return graph[from][to];
}

void MatrixGraph::AddV(int v)
{
	bool **new_graph = new bool*[vertexNumber + 1];
	for (int i = 0; i < vertexNumber + 1; ++i) {
		new_graph[i] = new bool[vertexNumber + 1];
		for (int j = 0; j < vertexNumber + 1; ++j)
			new_graph[i][j] = false;
	}
		

	for (int i = 0; i < vertexNumber; i++) {
		for (int j = 0; j < vertexNumber + 1; j++) {
			if (j < vertexNumber)
				new_graph[i][j] = graph[i][j];
			else
				new_graph[i][j] = false;
		}
	}
	/*for (int i = 0; i < vertexNumber; i++) 
		new_graph[i] = graph[i];
	
	for (int i = 0; i < vertexNumber + 1; i++) {
		new_graph[vertexNumber][i] = false;
	}*/
	graph = new_graph;
	vertexNumber++;
}

bool MatrixGraph::DeleteVertex(int v)
{
	if (v < 0 || v >= vertexNumber)
		return false;
	bool **new_graph = new bool*[vertexNumber - 1];
	for (int i = 0; i < vertexNumber - 1; i++)
		new_graph[i] = new bool[vertexNumber - 1];
	int c = 0, k = 0;
	for (int i = 0; i < vertexNumber; ++i) {
		if (i != v) {
			k = 0;
			for (int j = 0; j < vertexNumber; j++) {
				if (j != v) {
					new_graph[c][k] = graph[i][j];
					k++;
				}
			}
			c++;
		}
	}
	graph = new_graph;
	vertexNumber--;

	return true;
}
