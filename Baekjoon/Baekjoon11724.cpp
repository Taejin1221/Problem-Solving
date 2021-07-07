// Baekjoon11724_NumberOfConnectedComponent.cpp
// https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>
#include <queue>

#define FORLOOP(x) for ( int i = 0; i < x ; i++ )

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> adjList[1000];
	FORLOOP( m ) {
		int a, b;
		cin >> a >> b;

		adjList[a - 1].push_back(b - 1);
		adjList[b - 1].push_back(a - 1);
	}

	bool visited[1000] = { false, };

	int connected = 0;
	FORLOOP( n ) {
		if ( !visited[i] ) {
			visited[i] = true;
			queue<int> q;
			q.push( i );

			while ( !q.empty() ) {
				int curr = q.front(); q.pop();

				FORLOOP( ( adjList[curr].size() ) ) {
					int next = adjList[curr][i];
					if ( !visited[next] ) {
						visited[next] = true;
						q.push( next );
					}
				}
			}

			connected++;
		}
	}

	cout << connected << '\n';
	
	return 0;
}