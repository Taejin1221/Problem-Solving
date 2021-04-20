// Codeforces_1509B.cpp
#include <iostream>

#include <string>

using namespace std;

void solveTestCase( ) {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int numT = 0, numM = 0;
	int mIdx[100'000] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		if ( str[i] == 'T' )
			numT++;
		else
			mIdx[numM++] = i;
	}

	if ( 2 * numM != numT ) {
		cout << "NO\n";
		return;
	}

	bool visited[100'000] = { false, }, isPossible = true;
	int j = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( str[i] == 'T' ) {
			if ( i > mIdx[j] ) {
				isPossible = false;
				break;
			}
			j++;
			visited[i] = true;

			if ( j == numM )
				break;
		}
	}

	if ( j < numM )
		cout << "NO";
	else {
		j = numM - 1;
		for ( int i = n - 1; i >= 0; i-- ) {
			if ( str[i] == 'T' && !visited[i] ) {
				if ( i < mIdx[j] ) {
					isPossible = false;
					break;
				}
				j--;
				visited[i] = true;

				if ( j == -1 )
					break;
			}
		}

		if ( isPossible )
			cout << "YES";
		else
			cout << "NO";
	}

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
