// Baekjoon11758_CCW.cpp
// https://www.acmicpc.net/problem/11758
#include <iostream>

using namespace std;

int main(void) {
	pair<int, int> nums[3];

	for ( int i = 0; i < 3; i++ )
		cin >> nums[i].first >> nums[i].second;

	int op = ( nums[1].first - nums[0].first ) * ( nums[2].second - nums[0].second );
	op -= ( nums[2].first - nums[0].first ) * ( nums[1].second - nums[0].second );

	if ( op == 0 ) // linear
		cout << 0;
	else {
		if ( op > 0 ) // Counter Clock Wise
			cout << 1;
		else // Clock Wise
			cout << -1;
	}
	cout << '\n';

	return 0;
}