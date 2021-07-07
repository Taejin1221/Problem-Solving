// Baekjoon11405_BuyBook.cpp
// https://www.acmicpc.net/problem/11405
#include <iostream>
#include <queue>
#include <vector>
#include <climits> /* INT_MAX */
#include <algorithm> /* fill() */

#define endl '\n'
#define START 0
#define END 201
#define OFFSET 100
#define INF INT_MAX
#define MAX_ARR_SIZE 202

using namespace std;

vector<int> adjList[MAX_ARR_SIZE];
int weights[MAX_ARR_SIZE][MAX_ARR_SIZE];
int capacity[MAX_ARR_SIZE][MAX_ARR_SIZE];

int MCMF();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// Bookstore
	for ( int i = 1; i <= n; i++ ) {
		int real = i + OFFSET;
		cin >> capacity[real][END];

		adjList[END].push_back( real );
		adjList[real].push_back( END );
	}

	// People
	for ( int i = 1; i <= m; i++ ) {
		cin >> capacity[START][i];

		adjList[START].push_back( i );
		adjList[i].push_back( START );
	}

	// Delivery Cost
	for ( int i = 1; i <= m; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			int realJ = j + OFFSET;
			cin >> weights[i][realJ];
			weights[realJ][i] = -weights[i][realJ];

			capacity[i][realJ] = INF;

			adjList[i].push_back( realJ );
			adjList[realJ].push_back( i );
		}
	}

	cout << MCMF() << endl;

	return 0;
}

int MCMF() {
	int result = 0;
	int path[MAX_ARR_SIZE];
	bool isinQ[MAX_ARR_SIZE];
	int distance[MAX_ARR_SIZE];
	int flowed[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0, };

	while ( true ) {
		fill( path, path + MAX_ARR_SIZE, -1);
		fill( isinQ, isinQ + MAX_ARR_SIZE, false );
		fill( distance, distance + MAX_ARR_SIZE, INF );

		queue<int> q; q.push( START );
		isinQ[START] = true; distance[START] = 0;
		while ( !q.empty() ) {
			int curr = q.front(); q.pop();
			isinQ[curr] = false;

			for ( int adj: adjList[curr] ) {
				if ( (capacity[curr][adj] - flowed[curr][adj] > 0) && (distance[adj] > distance[curr] + weights[curr][adj]) ) {
					path[adj] = curr;
					distance[adj] = distance[curr] + weights[curr][adj];

					if ( !isinQ[adj] ) {
						q.push( adj );
						isinQ[adj] = true;
					}
				}
			}
		}

		if ( path[END] == -1 )
			break;

		int flow = INF;
		for ( int i = END; i != START; i = path[i] )
			flow = min( flow, capacity[path[i]][i] - flowed[path[i]][i] );

		for ( int i = END; i != START; i = path[i] ) {
			result += flow * weights[path[i]][i];
			flowed[path[i]][i] += flow;
			flowed[i][path[i]] -= flow;
		}
	}

	return result;
}