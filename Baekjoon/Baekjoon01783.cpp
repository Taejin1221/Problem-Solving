// Baekjoon01783_SickKnight.cpp
// https://www.acmicpc.net/problem/1783
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int maxRow, maxCol;
	cin >> maxRow >> maxCol;

	bool flag = true;
	int ans = 1, currCol = 1;
	if ( maxRow == 1 )
		ans = 1;
	else if ( maxRow == 2 )
		ans += ( maxCol - currCol ) / 2;
	else {
		if ( maxCol >= 7 ) {
			ans += 4;

			currCol = 7;

			flag = false;
		}

		ans += maxCol - currCol;
	}

	if ( flag && ans > 4 )
		cout << 4 << '\n';
	else
		cout << ans << '\n';

	return 0;
}