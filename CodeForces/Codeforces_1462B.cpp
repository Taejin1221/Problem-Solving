// Codeforces690_B.cpp
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		string str;
		cin >> str;

		int canMake = false;
		if ( str[0] == '2' && str[1] == '0' && str[2] == '2' && str[3] == '0' )
			canMake = true;
		else if ( str[0] == '2' && str[1] == '0' && str[2] == '2' && str[n - 1] == '0' )
			canMake = true;
		else if ( str[0] == '2' && str[1] == '0' && str[n - 2] == '2' && str[n - 1] == '0' )
			canMake = true;
		else if ( str[0] == '2' && str[n - 3] == '0' && str[n - 2] == '2' && str[n - 1] == '0' )
			canMake = true;
		else if ( str[n - 4] == '2' && str[n - 3] == '0' && str[n - 2] == '2' && str[n - 1] == '0' )
			canMake = true;
		
		cout << ( canMake ? "YES" : "NO" ) << '\n';
	}

	return 0;
}
