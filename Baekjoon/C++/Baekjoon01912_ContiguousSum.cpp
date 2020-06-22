// Baekjoon01912_ContiguousSum.cpp
// https://www.acmicpc.net/problem/1912
#include <iostream>

#define MAX_N_SIZE 100000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie( NULL );

	int n;
	cin >> n;

	int max = -1000;
	int nums[MAX_N_SIZE];
	for ( int i = 0; i < n; i++ ) {
		cin >> nums[i];
		max = (max < nums[i]) ? nums[i] : max;
	}

	int currSum = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( currSum + nums[i] > 0 ) {
			currSum += nums[i];
			max = ( max < currSum ) ? currSum : max;
		} else
			currSum = 0;
	}

	cout << max << '\n';

	return 0;
}