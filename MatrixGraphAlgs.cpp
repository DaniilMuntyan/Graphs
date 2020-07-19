#include "MatrixGraphAlgs.h"
#include <stack>
void MatrixGraphAlgs::processDFS(int k, vector<bool> &used, queue<pair<int, int>> &path)
{
	used[k] = true;
	for (int i = 0; i < CountVertex(); i++) {
		if (!used[i] && get_graph()[k][i]) {
			path.push(pair<int, int>(k, i));
			processDFS(i, used, path);
		}
	}
}

queue<pair<int, int>> MatrixGraphAlgs::DFS(int v)
{
	vector<bool> used(CountVertex(), false);
	queue<pair<int, int>> path;
	path.push(pair<int, int>(v, v));
	processDFS(v, used, path);
	for (int i = 0; i < CountVertex(); ++i) {
		if (!used[i]) {
			path.push(pair<int, int>(i, i));
			processDFS(i, used, path);
		}
	}
	return path;
}

void MatrixGraphAlgs::processBFS(int v, vector<int> &price, queue<pair<int, int>> &path)
{
	price[v] = 1;
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int to = 0; to < CountVertex(); ++to) {
			if (get_graph()[v][to] && price[to] == -1) {
				price[to] = price[to] + 1;
				path.push(pair<int, int>(v, to));
				q.push(to);
			}
		}
	}
}

queue<pair<int, int>> MatrixGraphAlgs::BFS(int start, vector<int> &price)
{
	queue<pair<int, int>> path;
	path.push(pair<int, int>(start, start));
	processBFS(start, price, path);
	for (int v = 0; v < CountVertex(); ++v)
	{
		if (price[v] == -1) {
			path.push(pair<int, int>(v, v));
			processBFS(v, price, path);
		}
	}
	return path;
}

vector<int> MatrixGraphAlgs::Euler()
{
	MatrixGraph *my_copy = new MatrixGraphAlgs(*this);
	vector<int> degree(my_copy->CountVertex(), 0);
	for (int i = 0; i < my_copy->CountVertex(); ++i) {
		for (int j = 0; j < my_copy->CountVertex(); ++j) {
			if (my_copy->get_graph()[i][j])
				degree[i]++;
		}
	}
	int first = 0;
	int v1 = -1, v2 = -1;
	bool bad = false, addArc = true, v1_to_v2 = false;
	for (int i = 0; i < my_copy->CountVertex(); ++i) {
		if (degree[i] % 2 != 0) {
			if (v1 == -1)
				v1 = i;
			else if (v2 == -1)
				v2 = i;
			else
				bad = true;
		}
	}
	if (v1 != -1) {
		v1_to_v2 = get_graph()[v1][v2];
		my_copy->AddArc(v1, v2);
		my_copy->AddArc(v2, v1);
		addArc = true;
		first = v1;
	}
	stack<int> st;
	st.push(first);
	vector<int> res;
	bool flag = false;
	while (!st.empty()) {
		int v = st.top();
		int i;
		for (i = 0; i < my_copy->CountVertex(); ++i) {
			if (my_copy->get_graph()[v][i])
				break;
		}
		if (i == my_copy->CountVertex()) {
			res.push_back(v);
			st.pop();
		}
		else {
			if (v1 != -1 && ((v1 == v && v2 == i) || (v2 == v && v1 == i)) && !flag && v1_to_v2) // �����
				flag = true;
			else {
				my_copy->DeleteArc(v, i);
				my_copy->DeleteArc(i, v);
			}
			st.push(i);
		}
	}
	if (v1 != -1 && addArc) {
		for (int i = 0; i < res.size() - 1; ++i) {
			if ((res[i] == v1 && res[i + 1] == v2) || (res[i] == v2 && res[i + 1] == v1)) {
				vector<int> res2;
				for (int j = i + 1; j < res.size(); j++)
					res2.push_back(res[j]);
				for (int j = 1; j <= i; ++j)
					res2.push_back(res[j]);
				res = res2;
				break;
			}
		}
	}
	for (int i = 0; i < my_copy->CountVertex(); ++i) {
		for (int j = 0; j < my_copy->CountVertex(); ++j)
			if (my_copy->get_graph()[i][j])
				bad = true;
	}
	if (bad)
		return vector<int>(0);
	else
		return res;
}

int MatrixGraphAlgs::search_ans(vector<pair<pair<int, int>, bool>> &ans, pair<pair<int, int>, bool> &element) {
	if (find(ans.begin(), ans.end(), element) != ans.end())
		return find(ans.begin(), ans.end(), element) - ans.begin();
	return -1;
}

void MatrixGraphAlgs::dfs_bridges(int v, int p, int &timer, vector<bool> &used, vector <int> &tin, vector<int> &fup, vector<pair<pair<int, int>, bool>> &ans) {
	used[v] = true;
	timer++;
	tin[v] = timer;
	fup[v] = timer;
	for (int to = 0; to < CountVertex(); ++to) {
		if (!get_graph()[v][to]) continue;
		if (to == p) continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			ans.push_back(pair<pair<int, int>, bool>(pair<int, int>(v, to), false));
			//ans.push_back(pair<pair<int, int>, bool>(pair<int, int>(v, to), false));
			dfs_bridges(to, v, timer, used, tin, fup, ans);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				pair<pair<int, int>, bool> res(pair<pair<int, int>, bool>(pair<int, int>(v, to), false));
				int i = search_ans(ans, res);
				if (i != -1)
					ans[i].second = true;
				else
					ans.push_back(res);
			}
		}
	}
}

vector<pair<pair<int, int>, bool>> MatrixGraphAlgs::find_bridges() {
	int timer = 0;
	vector<bool> used(CountVertex(), false);
	vector<int> tin(CountVertex()), fup(CountVertex());
	vector<pair<pair<int, int>, bool>> ans;
	for (int i = 0; i < CountVertex(); ++i) {
		if (!used[i])
			dfs_bridges(i, -1, timer, used, tin, fup, ans);
	}
	return ans;
}
