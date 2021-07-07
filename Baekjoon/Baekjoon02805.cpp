// Baekjoon02805_CuttingWood.cpp
// https://www.acmicpc.net/problem/2805
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int numWoods, lenWoods;
	cin >> numWoods >> lenWoods;

	int maxWoods = 0;
	int woods[1000000];
	for ( int i = 0; i < numWoods; i++ ) {
		cin >> woods[i];
		if ( maxWoods < woods[i] )
			maxWoods = woods[i];
	}

	int left = 0, right = maxWoods + 1;
	while ( left + 1 < right ) {
		int mid = ( left + right ) / 2;

		long long cutWood = 0;
		for ( int i = 0; i < numWoods; i++ )
			if ( woods[i] > mid )
				cutWood += woods[i] - mid;

		if ( cutWood >= lenWoods )
			left = mid;
		else
			right = mid;
	}

	cout << left << '\n';

	return 0;
}