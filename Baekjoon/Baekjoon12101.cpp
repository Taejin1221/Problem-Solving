// Baekjoon12101_Plus123II.cpp
// https://www.acmicpc.net/problem/12101
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > answers;

void backtracking( vector<int>& curr, int target ) {
	if ( target == 0 )
		answers.push_back( curr );
	else if ( target < 0 )
		return;
	else {
		for ( int i = 1; i <= 3; i++ ) {
			curr.push_back( i );
			backtracking( curr, target - i );
			curr.pop_back( );
		}
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;

	vector<int> curr;
	backtracking( curr, n );

	if ( k > answers.size() ) {
		cout << -1;
	} else {
		for ( int i = 0; i < answers[k - 1].size() - 1; i++  )
			cout << answers[k - 1][i] << '+';
		cout << answers[k - 1].back();
	}

	cout << endl;

	return 0;
}