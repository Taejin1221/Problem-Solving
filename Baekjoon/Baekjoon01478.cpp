// Baekjoon01478_CalculateCalendar.cpp
// https://www.acmicpc.net/problem/1476
#include <iostream>

using namespace std;

int main(void) {
	int ans[3];
	cin >> ans[0] >> ans[1] >> ans[2];

	int curr[3] = { 1, 1, 1 }, sol = 1;
	while ( !( curr[0] == ans[0] && curr[1] == ans[1] && curr[2] == ans[2] ) ) {
		curr[0]++;
		curr[1]++;
		curr[2]++;

		if ( curr[0] > 15 )
			curr[0] = 1;
		if ( curr[1] > 28 )
			curr[1] = 1;
		if ( curr[2] > 19 )
			curr[2] = 1;
		sol++;
	}

	cout << sol << endl;

	return 0;
}
