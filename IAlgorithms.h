#ifndef H_IALGORITHMS
#define H_IALGORITHMS

#include <list>
#include <vector>
#include <queue>
#include <map>
class IAlgorithms {
public:
	virtual queue<pair<int, int>> DFS(int start) = 0;
	virtual void processDFS(int k, vector<bool> &used, queue<pair<int, int>> &path) = 0;

	virtual queue<pair<int, int>> BFS(int start, vector<int> &price) = 0;
	virtual void processBFS(int v, vector<int> &price, queue<pair<int, int>> &path) = 0;

	virtual vector<int> Euler() = 0;

	virtual void dfs_bridges(int v, int p, int &timer, vector<bool> &used, vector <int> &tin, vector<int> &fup, vector<pair<pair<int, int>, bool>> &ans) = 0;
	virtual int search_ans(vector<pair<pair<int, int>, bool>> &ans, pair<pair<int, int>, bool> &element) = 0;
	virtual vector<pair<pair<int, int>, bool>> find_bridges() = 0;
};
#endif