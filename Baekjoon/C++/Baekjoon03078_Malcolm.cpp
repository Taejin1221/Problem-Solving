// Baekjoon03078_Malcolm.cpp
// https://www.acmicpc.net/problem/3078
#include <iostream>

#include <queue>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	long long ans = 0ll;
	queue<int> nameSize[21];
	for ( int i = 0; i < n; i++ ) {
		string name;
		cin >> name;

		queue<int>& q = nameSize[name.size()];
		while ( !q.empty() && (i - q.front()) > k ) {
			q.pop();
			ans += q.size();
		}

		q.push( i );
	}

	for ( int i = 2; i <= 20; i++ ) {
		queue<int>& q = nameSize[i];
		while ( !q.empty() ) {
			q.pop();
			ans += q.size();
		}
	}

	cout << ans << '\n';

	return 0;
}