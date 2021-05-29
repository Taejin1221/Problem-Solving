// Baekjoon19538_Rumor.cpp
// https://www.acmicpc.net/problem/19538
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 200'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> adjList[SIZE];
	int rumorPeople[SIZE], minute[SIZE];

	fill( rumorPeople + 1, rumorPeople + n + 1, 0 );
	fill( minute + 1, minute + n + 1, -1 );

	for ( int i = 1; i <= n; i++ ) {
		int temp;
		cin >> temp;

		while ( temp ) {
			adjList[i].push_back( temp );
			cin >> temp;
		}
	}

	queue<int> q;

	int m;
	cin >> m;
	for ( int i = 0; i < m; i++ ) {
		int rumor;
		cin >> rumor;

		minute[rumor] = 0;
		q.push( rumor );
	}

	while ( !q.empty() ) {
		int curr = q.front(); q.pop();

		for ( int& adj : adjList[curr] ) {
			if ( (minute[adj] == -1)
				&& (++rumorPeople[adj] >= (adjList[adj].size() + 1) / 2) ) {
				minute[adj] = minute[curr] + 1;
				q.push( adj );
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
		cout << minute[i] << ' ';
	cout << '\n';

	return 0;
}