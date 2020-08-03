// Baekjoon18870_CoordinateCompression.cpp
// https://www.acmicpc.net/problem/18870
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int coords[1'000'000];
	vector<int> comp;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		coords[i] = temp;
		comp.push_back( temp );
	}

	sort( comp.begin(), comp.end() );
	comp.erase( unique( comp.begin(), comp.end() ), comp.end() );

	for ( int i = 0; i < n; i++ ) {
		int idx = lower_bound( comp.begin(), comp.end(), coords[i] ) - comp.begin();
		cout << idx << ' ';
	}
	cout << '\n';

	return 0;
}