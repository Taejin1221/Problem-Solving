// Baekjoon09935_StringExplosion.cpp
// https://www.acmicpc.net/problem/9935
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string origin;
	cin >> origin;

	string explosion;
	cin >> explosion;

	char last = explosion.back();

	vector<char> stck;
	for ( char& c : origin ) {
		stck.push_back( c );
		if ( c == last ) {
			bool isExp = true;

			int j = stck.size() - 1;
			for ( int i = explosion.size() - 1; i >= 0; i--, j-- ) {
				if ( j < 0 || explosion[i] != stck[j] ) {
					isExp = false;
					break;
				}
			}

			if ( isExp )
				for ( int i = 0; i < explosion.size(); i++ )
					stck.pop_back();
		}
	}

	if ( stck.empty() )
		cout << "FRULA";
	else
		for ( int i = 0; i < stck.size(); i++ )
			cout << stck[i];
	cout << '\n';

	return 0;
}
