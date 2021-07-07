// Baekjoon15903_PlayCardAdd.cpp
// https://www.acmicpc.net/problem/15903
// UCPC 2018 Preliminary B
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;
		pq.push( temp );
	}

	for ( int i = 0; i < m; i++ ) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();

		pq.push( a + b );
		pq.push( a + b );
	}

	ll sum = 0;
	for ( int i = 0; i < n; i++ ) {
		sum += pq.top(); pq.pop();
	}

	cout << sum << '\n';

	return 0;
}