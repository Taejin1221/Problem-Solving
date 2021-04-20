// Codeforces_1514C.cpp
#include <iostream>

#include <vector>

using namespace std;

long long gcd( long long a, long long b ) {
	return b ? gcd( b, a % b ) : a;
}

void solveTestCase( ) {
	int n;
	cin >> n;

	vector<int> ans;

	long long prod = 1ll;
	for ( int i = 1; i < n; i++ ) {
		if ( gcd( i, n ) == 1 ) {
			ans.push_back( i );
			prod = prod * i % n;
		}
	}

	int except = 0;
	if ( prod != 1 ) {
		except = ans.back();
		cout << ans.size() - 1 << '\n';
	} else
		cout << ans.size() << '\n';

	for ( int& val : ans )
		if ( val != except )
			cout << val << ' ';
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
