#include "ListGraph.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <msclr\marshal_cppstd.h>

void ListGraph::printOriginalGraph(Graphics ^gr, SolidBrush ^brush, Pen^ penGraph, Pen^ penWhite, map<int, Dot> &my_map, int width, int height, int radius)
{
	gr->Clear(Color::White);
	for (int i = 0; i < vertexNumber; ++i)
	{
		list<int> &temp = graph[i];
		//my_map[i].drawEllipse(gr, penWhite, radius);
		for (int v : temp)
		{
			my_map[i].drawTo(gr, penGraph, my_map[v]);
			my_map[v].drawPoint(gr, brush, width, height, v + 1);
		}
		my_map[i].drawPoint(gr, brush, width, height, i + 1);
	}
}

System::String^ ListGraph::getView() {
	System::String^ s = "Граф представлено списком суміжності\n";
	for (int i = 0; i < vertexNumber; ++i) {
		list<int> &temp = graph[i];
		s += (i + 1).ToString() + ": ";
		for (int v : temp)
			s += (v + 1).ToString() + " ";
		s += "\n";
	}
	return s;
}

System::String^ ListGraph::getGraph()
{
	System::String^ s = vertexNumber + "\n";
	for (int i = 0; i < vertexNumber; ++i)
	{
		list<int> &temp = graph[i];
		s += (i + 1).ToString() + ": ";
		for (int v : temp)
		{
			s += (v + 1).ToString() + " ";
		}
		s += "\n";
	}
	return s;
}

void ListGraph::AddArc(int from, int to)
{
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return;
	graph[from].push_back(to);
	
}

bool ListGraph::DeleteArc(int from, int to)
{
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return false;
	list<int> &list_from = graph[from];
	list<int>::iterator it = find(list_from.begin(), list_from.end(), to);
	if (it != list_from.end()) 
		list_from.erase(it);
	return true;
}

void ListGraph::Clear()
{
	this->vertexNumber = 0;
	this->graph = new list<int>[0];
}

bool ListGraph::HasArc(int from, int to) const
{
	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
		return false;
	return (find(graph[from].begin(), graph[from].end(), to) != graph[from].end());
}

void ListGraph::AddV(int v)
{
	list<int> *new_list = new list<int>[vertexNumber + 1];
	for (int i = 0; i < vertexNumber; i++)
		new_list[i].assign(graph[i].begin(), graph[i].end());
	graph = new_list;
	vertexNumber += 1;
}

bool ListGraph::DeleteVertex(int v)
{
	if (v < 0 || v >= vertexNumber)
		return false;
	list<int>::iterator it;
	for (int i = 0; i < vertexNumber; ++i)
	{
		list<int> &temp_list = graph[i];
		/*for (int j = 0; j < temp_list.size(); ++j)
		{*/
		it = find(temp_list.begin(), temp_list.end(), v);
		if (it != temp_list.end())
			temp_list.erase(it);
		//}
	}

	list<int> *new_list = new list<int>[vertexNumber - 1];
	int c = 0;
	for (int i = 0; i < vertexNumber; i++) {
		if (i != v) {
			new_list[c].assign(graph[i].begin(), graph[i].end());
			c++;
		}
	}
	*graph = *new_list;
	vertexNumber--;

	return true;
}

void ListGraph::ToListbox(System::Windows::Forms::ListBox^ listbox)
{
	listbox->Items->Clear();
	listbox->Items->Add("Список побудованих ребер:");
	vector<pair<int, int>> usedArc;
	for (int i = 0; i < vertexNumber; ++i)
	{
		list<int> &temp = graph[i];
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

System::String^ ListGraph::to_string()
{
	System::String^ s = "";
	for (int i = 0; i < vertexNumber; ++i)
	{
		list<int> &temp = graph[i];
		for (auto to : temp)
		{
			s += i.ToString() + " - " + to.ToString() + "\n";
		}
	}
	return s;
}