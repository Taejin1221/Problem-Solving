// Codeforces_1471B.cpp
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n, x;
		cin >> n >> x;

		long long sum = 0ll;
		queue<pair<ll, ll> > q;
		for ( int i = 0; i < n; i++ ) {
			int temp;
			cin >> temp;

			sum += temp;

			q.push( { temp, 1 } );
		}

		while ( !q.empty() ) {
			pair<ll, ll> curr = q.front(); q.pop();

			if ( curr.first % x == 0 ) {
				q.push( { curr.first / x, curr.second * x } );
				sum += (ll)curr.first / x * x * curr.second;
			} else
				break;
		}

		cout << sum << '\n';
	}

	return 0;
}
