#pragma once
#include "ListGraph.h"
#include "SetGraph.h"
#include "Graph.h"
class Handler : public Graph{
private:
	int view;
public:
	Handler(int v) : view(v) { }
	Handler() : view(0) { }

	virtual queue<pair<int, int>> DFS(int start);
	virtual void processDFS(int k, vector<bool> &used, queue<pair<int, int>> &path);

	virtual queue<pair<int, int>> BFS(int start, vector<int> &price);
	virtual void processBFS(int v, vector<int> &price, queue<pair<int, int>> &path);

	virtual vector<int> Euler();

	virtual void dfs_bridges(int v, int p, int &timer, vector<bool> &used, vector <int> &tin, vector<int> &fup, vector<pair<pair<int, int>, bool>> &ans);
	virtual int search_ans(vector<pair<pair<int, int>, bool>> &ans, pair<pair<int, int>, bool> &element);
	virtual vector<pair<pair<int, int>, bool>> find_bridges();


};