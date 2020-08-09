// Baekjoon05525_IOIOI.cpp
// https://www.acmicpc.net/problem/5525
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string str;

	cin >> n >> m;
	cin >> str;

	int idx = 0;
	vector<int> counts;
	while ( idx < m ) {
		if ( str[idx++] == 'I' ) {
			int count = 0;
			while ( (idx < m - 1) && (str[idx] == 'O' && str[idx + 1] == 'I') ) {
				count++;
				idx += 2;
			}
			counts.push_back( count );
		}
	}

	int ans = 0;
	for ( int v : counts )
		ans += ( v - n + 1 > 0 ) ? v - n + 1 : 0;

	cout << ans << '\n';

	return 0;
}