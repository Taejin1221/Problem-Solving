// Baekjoon02887.cpp
// https://www.acmicpc.net/problem/2887
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define ABS(x) ((x) > 0 ? x : -(x))

using namespace std;

struct Coordinate {
	int num;
	int coordinate[3];
};

struct Node {
	int vertex;
	int weight;

	Node(int v, int w): vertex(v), weight(w) { }

	bool operator<(const Node& n2) const {
		return weight > n2.weight;
	}
};

bool compareX(Coordinate& c1, Coordinate& c2);
bool compareY(Coordinate& c1, Coordinate& c2);
bool compareZ(Coordinate& c1, Coordinate& c2);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Coordinate coords[100'000];
	for (int i = 0; i < n; i++) {
		coords[i].num = i;
		cin >> coords[i].coordinate[0] >> coords[i].coordinate[1] >> coords[i].coordinate[2];
	}

	bool (*compare[3])(Coordinate& c1, Coordinate& c2) = { compareX, compareY, compareZ };

	vector<Node> adjList[100'000];
	for (int i = 0; i < 3; i++) {
		sort(coords, coords + n, compare[i]);

		adjList[coords[0].num].push_back(Node(coords[1].num, ABS(coords[0].coordinate[i] - coords[1].coordinate[i])));
		adjList[coords[n - 1].num].push_back(Node(coords[n - 2].num, ABS(coords[n - 1].coordinate[i] - coords[n - 2].coordinate[i])));
		for (int j = 1; j < n - 1; j++) {
			adjList[coords[j].num].push_back(Node(coords[j - 1].num, ABS(coords[j].coordinate[i] - coords[j - 1].coordinate[i])));
			adjList[coords[j].num].push_back(Node(coords[j + 1].num, ABS(coords[j].coordinate[i] - coords[j + 1].coordinate[i])));
		}
	}

	priority_queue<Node> pq;
	bool visited[100'000] = { false, };

	pq.push(Node(0, 0));

	int visitedNodeNum = 0;
	long long ans = 0ll;
	while (!pq.empty() && visitedNodeNum < n) {
		Node curr = pq.top(); pq.pop();

		if (!visited[curr.vertex]) {
			visited[curr.vertex] = true;
			ans += curr.weight;
			visitedNodeNum++;

			for (Node& adj : adjList[curr.vertex]) {
				if (!visited[adj.vertex]) {
					pq.push(adj);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

bool compareX(Coordinate& c1, Coordinate& c2) {
	return c1.coordinate[0] < c2.coordinate[0];
}

bool compareY(Coordinate& c1, Coordinate& c2) {
	return c1.coordinate[1] < c2.coordinate[1];
}

bool compareZ(Coordinate& c1, Coordinate& c2) {
	return c1.coordinate[2] < c2.coordinate[2];
}
