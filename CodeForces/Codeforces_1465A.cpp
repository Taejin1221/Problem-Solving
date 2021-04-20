// Codeforces_692_A.cpp
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

		int bracket = 0, idx = str.size() - 1;
		while ( idx >= 0 && str[idx] == ')' )
			idx--, bracket++;

		if ( bracket > str.size() / 2 )
			cout << "Yes";
		else
			cout << "No";
		cout << '\n';
	}

	return 0;
}
