// Baekjoon01015_SortArray.cpp
// https://www.acmicpc.net/problem/1015
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int a[50], p[50] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		cin >> a[i];
		p[i] = -1;
	}

	for ( int i = 0; i < n; i++ ) {
		int minIdx = -1;
		for ( int j = 0; j < n; j++ )
			if ( p[j] == -1 )
				if ( minIdx == -1 || a[j] < a[minIdx] )
					minIdx = j;

		p[minIdx] = i;
	}

	for ( int i = 0; i < n; i++ )
		cout << p[i] << ' ';
	cout << '\n';

	return 0;
}