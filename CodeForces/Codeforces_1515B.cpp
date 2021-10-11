// Codeforces_1515B.cpp
#include <iostream>

#include <set>

using namespace std;

set<int> table;

void solveTestCase( ) {
	int n;
	cin >> n;

	if (table.find(n) == table.end())
		cout << "NO";
	else
		cout << "YES";
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long value = 2;
	for (int i = 2; value < 1'000'000'000; i++) {
		table.insert(value);
		value = 2 * (i * i);
	}

	value = 4;
	for (int i = 2; value < 1'000'000'000; i++) {
		table.insert(value);
		value = 4 * (i * i);
	}

	int t;
	cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
