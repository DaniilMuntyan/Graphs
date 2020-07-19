#include "SetGraph.h"
#include <vector>
#include <stack>
SetGraph::~SetGraph() {
	for (int i = 0; i < vertexNumber; ++i) {
		delete &graph[i];
	}
	delete[] &graph;
}

void SetGraph::AddV(int v)
{
	multiset<int> *new_set = new multiset<int>[vertexNumber + 1];
	for (int i = 0; i < vertexNumber; ++i) {
		new_set[i] = graph[i];
	}
	graph = new_set;
	vertexNumber++;
}

bool SetGraph::DeleteVertex(int v)
{
	if (v < 0 || v >= vertexNumber)
		return false;
	multiset<int>::iterator it;
	for (int i = 0; i < vertexNumber; ++i)
	{
		multiset<int> &temp_list = graph[i];
		it = find(temp_list.begin(), temp_list.end(), v);
		if (it != temp_list.end())
			temp_list.erase(it);
	}

	multiset<int> *new_set = new multiset<int>[vertexNumber - 1];
	int c = 0;
	for (int i = 0; i < vertexNumber - 1; i++) {
		new_set[i] = graph[i];
	}
	*graph = *new_set;
	vertexNumber--;
	return true;
}

void SetGraph::Clear()
{
	this->vertexNumber = 0;
	this->graph = new multiset<int>[0];
}

void SetGraph::AddArc(int from, int to) {
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return;
	graph[from].insert(to);
}

bool SetGraph::DeleteArc(int from, int to)
{
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return false;

	multiset<int> &set_from = graph[from];
	multiset<int>::iterator it = find(set_from.begin(), set_from.end(), to);
	if (it != set_from.end())
		set_from.erase(it);
	return true;
}

bool SetGraph::HasArc(int from, int to) const {
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber) {
		return false;
	}
	return graph[from].count(to);
}

System::String^ SetGraph::getView() {
	System::String^ s = "Граф представлено множинами суміжності (сет граф)\n";
	bool flag = false;
	for (int i = 0; i < vertexNumber; ++i) {
		flag = false;
		multiset<int> &temp = graph[i];
		s += (i + 1).ToString() + ": (";
		for (auto it = temp.begin(); it != temp.end(); ++it) {
			s += (*it + 1).ToString();
			s += ", ";
			flag = true;
		}
		if (flag)
			s = s->Remove(s->Length - 2) + ")\n";
		else {
			s = s->Remove(s->Length - 1) + "()\n";
		}
		/*for (int v : temp)
			s += (v + 1).ToString() + ", ";
		s += "\n";*/
	}
	return s;
}

System::String^ SetGraph::getGraph()
{
	System::String^ s = vertexNumber + "\n";
	for (int i = 0; i < vertexNumber; ++i)
	{
		multiset<int> &temp = graph[i];
		s += (i + 1).ToString() + ": ";
		for (int v : temp)
		{
			s += (v + 1).ToString() + " ";
		}
		s += "\n";
	}
	return s;
}

void SetGraph::printOriginalGraph(Graphics ^gr, SolidBrush ^brush, Pen^ penGraph, Pen^ penWhite, std::map<int, Dot> &my_map, int width, int height, int radius)
{
	gr->Clear(Color::White);
	for (int i = 0; i < vertexNumber; ++i)
	{
		multiset<int> &temp = graph[i];
		//my_map[i].drawEllipse(gr, penWhite, radius);
		for (int v : temp) {
			my_map[i].drawTo(gr, penGraph, my_map[v]);
			my_map[v].drawPoint(gr, brush, width, height, v + 1);
		}
		my_map[i].drawPoint(gr, brush, width, height, i + 1);
		
	}
}

void SetGraph::ToListbox(System::Windows::Forms::ListBox^ listbox)
{
	listbox->Items->Clear();
	listbox->Items->Add("Список побудованих ребер:");
	vector<pair<int, int>> usedArc;
	for (int i = 0; i < vertexNumber; ++i)
	{
		multiset<int> &temp = graph[i];
		for (int v : temp)
		{
			if (v != i && find(usedArc.begin(), usedArc.end(), pair<int, int>(v, i)) == usedArc.end()) {
				listbox->Items->Add((i + 1).ToString() + " - " + (v + 1).ToString());
				usedArc.push_back(pair<int, int>(i, v));
				usedArc.push_back(pair<int, int>(v, i));
			}
		}
	}
}
