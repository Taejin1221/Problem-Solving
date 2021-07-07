// Baekjoon10815_NumberCard.cpp
// https://www.acmicpc.net/problem/10815
#include <iostream>

#define MAX 20'000'001
#define OFFSET 10'000'000

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	bool table[MAX] = { false, };
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		table[temp + OFFSET] = true;
	}

	int m;
	cin >> m;
	while ( m-- ) {
		int temp;
		cin >> temp;

		cout << (int)table[temp + OFFSET] << ' ';
	}
	cout << '\n';

	return 0;
}