#ifndef H_MATRIXGRAPHALGS
#define H_MATRIXGRAPHALGS

#include "MatrixGraph.h"
#include <queue>
#include <vector>
class MatrixGraphAlgs : public MatrixGraph {
public:
	MatrixGraphAlgs() {}
	MatrixGraphAlgs(int n): MatrixGraph(n) {}
	MatrixGraphAlgs(MatrixGraph *copy) : MatrixGraph(*copy) {}

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