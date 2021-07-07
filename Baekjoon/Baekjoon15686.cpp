// Baekjoon15686_ChickenDelivery.cpp
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <climits> /* INT_MAX */
#include <vector>

#define ABS(x) (((x) > 0) ? (x) : (-(x)))

using namespace std;

int n, m;
int minDis = INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int chickenSize;

void dfs( int idx, vector<pair<int ,int>> prevChicken );
int CalChickenDistance( vector<pair<int, int>>& selectedChicken );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int matrix[50][50];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ ) {
			cin >> matrix[i][j];
			if ( matrix[i][j] == 1 )
				home.push_back( { i, j } );
			else if ( matrix[i][j] == 2 )
				chicken.push_back( { i, j } );
		}

	chickenSize = chicken.size();
	dfs( 0, vector<pair<int, int>> () );

	cout << minDis << '\n';

	return 0;
}

void dfs( int idx, vector<pair<int ,int>> prevChicken ) {
	if ( prevChicken.size() == m ) {
		int dis = CalChickenDistance( prevChicken );
		if ( dis < minDis )
			minDis = dis;
	} else {
		for ( int i = idx; i < chickenSize; i++ ) {
			prevChicken.push_back( chicken[i] );
			dfs( i + 1, prevChicken );
			prevChicken.pop_back( );
		}
	}
}

int CalChickenDistance( vector<pair<int, int>>& selectedChicken ) {
	int cityChickDis = 0;
	for ( int i = 0; i < home.size(); i++ ) {
		int chickDis = INT_MAX;
		for ( int j = 0; j < selectedChicken.size(); j++ ) {
			int currDis = ( ABS(home[i].first - selectedChicken[j].first ) +
				ABS(home[i].second - selectedChicken[j].second ) );
			if ( currDis < chickDis )
				chickDis = currDis;
		}
		cityChickDis += chickDis;
	}

	return cityChickDis;
}
