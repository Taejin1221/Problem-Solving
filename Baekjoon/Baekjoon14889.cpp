// Baekjoon14889_StartandLink.cpp
// https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

int n;

void dfs( vector< vector<int> >& combs, vector<int> prevArr, int idx, int size );
vector< vector<int> > combinations( int size );

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie( NULL );
	cout.tie( NULL );
	
	int scores[20][20];
	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> scores[i][j];
	
	int teamNum = n / 2, min = INT_MAX;
	vector< vector<int> > combs = combinations( teamNum );
	for ( int idx = 0; idx < combs.size() / 2; idx++ ) {
		vector<int> team1 = combs[idx];
		vector<int> team2 = combs[combs.size() - 1 - idx];

		int score1 = 0, score2 = 0;
		for ( int i = 0; i < teamNum - 1; i++ )
			for ( int j = i + 1; j < teamNum; j++ ) {
				score1 += scores[team1[i]][team1[j]];
				score1 += scores[team1[j]][team1[i]];
			}

		for ( int i = 0; i < teamNum - 1; i++ )
			for ( int j = i + 1; j < teamNum; j++ ) {
				score2 += scores[team2[i]][team2[j]];
				score2 += scores[team2[j]][team2[i]];
			}

		int diff = abs( score1 - score2 );
		if ( min > diff )
			min = diff;
	}

	cout << min << '\n';

	return 0;
}

void dfs( vector< vector<int> >& combs, vector<int> prevArr, int idx, int size ) {
	if ( size == prevArr.size() )
		combs.push_back( prevArr );
	else {
		for ( int i = idx; i < n; i++ ) {
			prevArr.push_back( i );
			dfs( combs, prevArr, i + 1, size );
			prevArr.pop_back( );
		}
	}
}

vector< vector<int> > combinations( int size ) {
	vector< vector<int> > combs;

	dfs( combs, vector<int> (), 0, size );

	return combs;
}
