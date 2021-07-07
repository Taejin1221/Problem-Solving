// Baekjoon09375_Incognito.cpp
// https://www.acmicpc.net/problem/9375
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		int len = 0;
		int arr[30] = { 0, };
		map<string, int> table;

		for ( int i = 0; i < n; i++ ) {
			string name, category;
			cin >> name >> category;

			if ( !table[category] ) {
				table[category] = len + 1;
				arr[len++] = 1;
			} else
				arr[table[category] - 1]++;
		}

		int cases = 1;
		for ( int i = 0; i < len; i++ )
			cases *= arr[i] + 1;
		cout << (cases - 1) << '\n';
	}

	return 0;
}