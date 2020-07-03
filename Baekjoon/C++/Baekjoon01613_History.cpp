// Baekjoon01613_History.cpp
// https://www.acmicpc.net/problem/1613
#include <iostream>

#define PREV "-1"
#define NEXT '1'
#define NOPE 0
#define endl '\n'

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool events[401][401] = { false, };
	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		events[a][b] = true;
	}

	for ( int k = 1; k <= n; k++ )
		for ( int i = 1; i <= n; i++ )
			for ( int j = 1; j <= n; j++ )
				if ( events[i][k] && events[k][j] )
					events[i][j] = 1;

	int s;
	cin >> s;
	for ( int i = 0; i < s; i++ ) {
		int a, b;
		cin >> a >> b;

		if ( events[a][b] )
			cout << PREV;
		else if ( events[b][a] )
			cout << NEXT;
		else
			cout << NOPE;
		cout << endl;
	}

	return 0;
}