#pragma once
#ifndef H_LISTGRAPHALGS
#define H_LISTGRAPHALGS

#include "ListGraph.h"
#include <queue>
#include <vector> 
class ListGraphAlgs: public ListGraph {
public:
	ListGraphAlgs() {}
	ListGraphAlgs(int n) : ListGraph(n) {}
	ListGraphAlgs(ListGraph *copy) : ListGraph(*copy) {}

	queue<pair<int, int>> DFS(int start);
	void processDFS(int k, vector<bool> &used, queue<pair<int, int>> &path);

	queue<pair<int, int>> BFS(int start, vector<int> &price);
	void processBFS(int v, vector<int> &price, queue<pair<int, int>> &path);

	vector<int> Euler();

	void dfs_bridges(int v, int p, int &timer, vector<bool> &used, vector <int> &tin, vector<int> &fup, vector<pair<pair<int, int>, bool>> &ans);
	int search_ans(vector<pair<pair<int, int>, bool>> &ans, pair<pair<int, int>, bool> &element);
	vector<pair<pair<int, int>, bool>> find_bridges();
};
#endif