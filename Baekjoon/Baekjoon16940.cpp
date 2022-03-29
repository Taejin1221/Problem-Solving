// Baekjoon16940.cpp
// https://www.acmicpc.net/problem/16940
#include <iostream>

#include <vector>

using namespace std;

int parent[100001], childNum[100001];
vector<int> adjList[100001];

// DFS
void getTreeInfo(int me, int mom) {
	for (int& c : adjList[me]) {
		if (c != mom) {
			childNum[me]++;
			parent[c] = me;
			getTreeInfo(c, me);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	int visitOrder[100001];
	for (int i = 0; i < n; i++)
		cin >> visitOrder[i];

	getTreeInfo(1, 0);

	bool isRightOrder = true;
	int par = 0, child = 1;
	for (; child < n; child++) {
		int currChild = visitOrder[child];

		// 자식이 0개인 노드는 지나감
		int currParent = visitOrder[par];
		while (childNum[currParent] == 0)
			currParent = visitOrder[++par];

		if (parent[currChild] == currParent) {
			childNum[currParent]--;
		} else {
			isRightOrder = false;
			break;
		}
	}
	
	cout << isRightOrder << '\n';
	
	return 0;
}
