// Baekjoon10867_SortWithoutDuplicate.cpp
// https://www.acmicpc.net/problem/10867
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int counting[2001] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;
		counting[temp + 1000]++;
	}

	for ( int i = 0; i < 2001; i++ ) {
		if ( counting[i] )
			cout << (i - 1000) << ' ';
	}

	cout << '\n';

	return 0;
}