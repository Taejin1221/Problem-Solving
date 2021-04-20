// Codeforces_1469A.cpp
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		string str;
		cin >> str;

		if ( str.size() % 2 )
			cout << "NO";
		else {
			if ( str.front() == ')' || str.back() == '(' )
				cout << "NO";
			else
				cout << "YES";
		}
		cout << '\n';
	}

	return 0;
}
