// Baekjoon01159_BasketballGame.cpp
// https://www.acmicpc.net/problem/1159
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	bool can = false;
	int first[26] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		string temp;
		cin >> temp;

		first[temp[0] - 'a']++;

		if ( first[temp[0] - 'a'] >= 5 )
			can = true;
	}

	if ( can ) {
		for ( int i = 0; i < 26; i++ )
			if ( first[i] >= 5 )
				cout << (char)(i + 'a');
		cout << '\n';
	} else
		cout << "PREDAJA\n";

	return 0;
}