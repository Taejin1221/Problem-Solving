// Codeforces_1480B.cpp
#include <iostream>

using namespace std;

void solveTestCase( ) {
	int heroAttack, heroHealth, n;
	cin >> heroAttack >> heroHealth >> n;

	int monsterAttack[100'000], monsterHealth[100'000];
	for ( int i = 0; i < n; i++ )
		cin >> monsterAttack[i];

	long long sum = 0ll;
	for ( int i = 0; i < n; i++ ) {
		cin >> monsterHealth[i];
		sum += (long long)( monsterHealth[i] + heroAttack - 1 ) / heroAttack * monsterAttack[i];
	}

	bool canWin = false;
	for ( int i = 0; i < n; i++ ) {
		if ( sum - monsterAttack[i] < heroHealth ) {
			canWin = true;
			break;
		}
	}

	if ( canWin )
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
