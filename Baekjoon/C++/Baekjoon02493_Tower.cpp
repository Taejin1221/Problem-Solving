// Baekjoon02493_Tower.cpp
// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<pii> stck;
	for ( int i = 0; i < n; i++ ) {
		int curr;
		cin >> curr;

		while ( !stck.empty() && stck.back().first < curr )
			stck.pop_back();

		if ( stck.empty() )
			cout << 0;
		else
			cout << stck.back().second + 1;
		cout << ' ';

		stck.push_back( { curr, i } );
	}
	cout << '\n';

	return 0;
}