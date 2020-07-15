// Baekjoon11409_Yulgang6.cpp
// https://www.acmicpc.net/problem/11409
#include <iostream>
#include <queue>
#include <vector>
#include <climits> /* INT_MAX */
#include <algorithm> /* fill() */

#define endl '\n'
#define INF INT_MAX
#define START 0
#define END 801
#define OFFSET 400
#define MAX_ARR_SIZE 802

using namespace std;

int tasks, salary;
vector<int> adjList[MAX_ARR_SIZE];
int weights[MAX_ARR_SIZE][MAX_ARR_SIZE];
int capacity[MAX_ARR_SIZE][MAX_ARR_SIZE];

void MCMF( int start, int end );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ ) {
		adjList[START].push_back( i );
		adjList[i].push_back( START );

		capacity[START][i] = 1;
	}

	for ( int i = 1; i <= n; i++ ) {
		int time;
		cin >> time;

		while ( time-- ) {
			int job, weight;
			cin >> job >> weight;

			job += OFFSET;

			adjList[i].push_back( job );
			adjList[job].push_back( i );

			capacity[i][job] = 1;

			weights[i][job] = -weight;
			weights[job][i] = weight;
		}
	}

	for ( int j = 1; j <= m; j++ ) {
		adjList[j + OFFSET].push_back( END );
		adjList[END].push_back( j + OFFSET );

		capacity[j + OFFSET][END] = 1;
	}

	MCMF( START, END );
	salary *= -1;

	cout << tasks << endl;
	cout << salary << endl;

	return 0;
}

void MCMF( int start, int end ) {
	int path[MAX_ARR_SIZE];
	int distance[MAX_ARR_SIZE];
	int flowed[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0, };
	bool isinQ[MAX_ARR_SIZE];

	while ( true ) {
		fill( path, path + MAX_ARR_SIZE, -1 );
		fill( isinQ, isinQ + MAX_ARR_SIZE, false );
		fill( distance, distance + MAX_ARR_SIZE, INF );

		queue<int> q; q.push( start );
		isinQ[start] = true; distance[start] = 0;
		while ( !q.empty() ) {
			int curr = q.front(); q.pop();
			isinQ[curr] = false;

			for ( int adj: adjList[curr] ) {
				if ( (capacity[curr][adj] - flowed[curr][adj] > 0) && (distance[adj] > distance[curr] + weights[curr][adj] ) ) {
					path[adj] = curr;
					distance[adj] = distance[curr] + weights[curr][adj];

					if ( !isinQ[adj] ) {
						q.push( adj );
						isinQ[adj] = true;
					}
				}
			}
		}

		if ( path[end] == -1 )
			break;

		int flow = INF;
		for ( int i = end; i != start; i = path[i] )
			flow = min( flow, capacity[path[i]][i] - flowed[path[i]][i] );

		for ( int i = end; i != start; i = path[i] ) {
			salary += flow * weights[path[i]][i];
			flowed[path[i]][i] += flow;
			flowed[i][path[i]] -= flow;
		}
		tasks++;
	}
}