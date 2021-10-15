// Codeforces_1593A.cpp
#include <iostream>

using namespace std;

void solveTestCase( ) {
	int a, b, c;
	cin >> a >> b >> c;

	int maxVal = max(a, max(b, c));
	if (a > b && a > c)
		cout << 0 << ' ';
	else
		cout << maxVal - a + 1 << ' ';

	if (b > a && b > c)
		cout << 0 << ' ';
	else
		cout << maxVal - b + 1 << ' ';

	if (c > a && c > b)
		cout << 0 << ' ';
	else
		cout << maxVal - c + 1 << ' ';
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
