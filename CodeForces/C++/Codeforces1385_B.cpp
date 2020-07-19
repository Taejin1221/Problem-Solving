// Codeforces1385_B.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		vector<int> values;
		bool isin[51] = { false, };
		for ( int i = 0; i < n * 2; i++ ) {
			int temp;
			cin >> temp;

			if ( !isin[temp] ) {
				values.push_back( temp );
				isin[temp] = true;
			}
		}

		for ( int v : values )
			cout << v << ' ';
		cout << '\n';
	}

	return 0;
}