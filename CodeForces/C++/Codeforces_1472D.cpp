// Codeforces_1472D.cpp
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		priority_queue<int> even, odd;
		for ( int i = 0; i < n; i++ ) {
			int temp;
			cin >> temp;

			if ( temp % 2 )
				odd.push( temp );
			else
				even.push( temp );
		}

		long long alice = 0LL, bob = 0LL;
		for ( int i = 0; i < n; i++ ) {
			// Alice
			if ( i % 2 == 0 ) {
				if ( !odd.empty() && (even.empty() || odd.top() > even.top()) )
					odd.pop();
				else {
					alice += even.top();
					even.pop();
				}
			} else {
				if ( !even.empty() && (odd.empty() || even.top() > odd.top()) )
					even.pop();
				else {
					bob += odd.top();
					odd.pop();
				}
			}
		}

		if ( alice > bob )
			cout << "Alice";
		else if ( alice < bob )
			cout << "Bob";
		else
			cout << "Tie";
		cout << '\n';
	}

	return 0;
}
