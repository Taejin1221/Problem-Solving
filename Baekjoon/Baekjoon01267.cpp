// Baekjoon01267_HandphoneCharge.cpp
// https://www.acmicpc.net/problem/1267
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int ySum = 0, mSum = 0;

	for ( int i = 0; i < n; i++ ) {
		int time;
		cin >> time;

		ySum += (time / 30 + 1) * 10;
		mSum += (time / 60 + 1) * 15;
	}

	if ( ySum > mSum )
		cout << "M " << mSum;
	else if ( mSum > ySum )
		cout << "Y " << ySum;
	else
		cout << "Y M " << ySum;
	cout << '\n';

	return 0;
}