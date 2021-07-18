// Baekjoon13418.cpp
// https://www.acmicpc.net/problem/13418
#include <iostream>

#include <vector>

using namespace std;

class UnionFindTree {
private:
	int* parent;

public:
	UnionFindTree(int size) {
		parent = new int[size];
		for (int i = 0; i < size; i++)
			parent[i] = i;
	}

	~UnionFindTree() {
		delete[] parent;
	}

	int find(int target) {
		return (parent[target] == target) ? target : parent[target] = find(parent[target]);
	}

	void unionTwoNode(int aRoot, int bRoot) {
		if (aRoot < bRoot)
			parent[bRoot] = aRoot;
		else
			parent[aRoot] = bRoot;
	}
};

struct Edge {
	int startNode, endNode;

	Edge(int s, int e): startNode(s), endNode(e) { }
};

typedef long long ll;
typedef pair<int, int> pii;

pii getMST(int n, vector<Edge>& firstEdges, vector<Edge>& secondEdges) {
	UnionFindTree tree(n + 1);

	pii result = { 0, 0 };
	for (Edge& edge : firstEdges) {
		int aRoot = tree.find(edge.startNode), bRoot = tree.find(edge.endNode);
		if (aRoot != bRoot) {
			tree.unionTwoNode(aRoot, bRoot);
			result.first++;
		}
	}

	for (Edge& edge : secondEdges) {
		int aRoot = tree.find(edge.startNode), bRoot = tree.find(edge.endNode);
		if (aRoot != bRoot) {
			tree.unionTwoNode(aRoot, bRoot);
			result.second++;
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges[2];
	for (int i = 0; i < m + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[c].push_back(Edge(a, b));
	}

	pii maxResult = getMST(n, edges[0], edges[1]);
	pii minResult = getMST(n, edges[1], edges[0]);

	cout << (ll)maxResult.first * maxResult.first - (ll)minResult.second * minResult.second << '\n';

	return 0;
}