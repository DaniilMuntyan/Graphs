#pragma once
#ifndef H_SETGRAPHALGS
#define H_SETGRAPHALGS

#include "SetGraph.h"
#include <queue>
#include <vector> 
class SetGraphAlgs : public SetGraph {
public:
	SetGraphAlgs() {}
	SetGraphAlgs(int n) : SetGraph(n) {}
	SetGraphAlgs(SetGraph *copy) : SetGraph(*copy) {}

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