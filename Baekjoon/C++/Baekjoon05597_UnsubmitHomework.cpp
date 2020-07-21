// Baekjoon05597_UnsubmitHomework.cpp
// https://www.acmicpc.net/problem/5597
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool isSubmit[31] = { false, };
	for ( int i = 0; i < 28; i++ ) {
		int submit;
		cin >> submit;

		isSubmit[submit] = true;
	}

	for ( int i = 1; i <= 30; i++ )
		if ( !isSubmit[i] )
			cout << i << '\n';

	return 0;
}